/**
 * @file WebsocketHandler.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 06:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/WebsocketHandler.hpp"

#include "dppcord/websocket/api/gateway/GatewayOpCodes.hpp"

#include "dppcord/websocket/api/gateway/events/DispatchEvents.hpp"

namespace dppcord
{
WebsocketHandler::WebsocketHandler(const std::string &token, DiscordClient *pDiscordClient) : m_lastSequence(0), m_token(token), m_heartbeater(this, 0)
{
    m_connection = new WebsocketConnection(boost::bind(&WebsocketHandler::processWebsocketMessage, this, boost::placeholders::_1));

    m_eventDispatcher.addEvent("READY", new ReadyEvent(pDiscordClient));
    m_eventDispatcher.addEvent("GUILD_CREATE", new GuildCreateEvent(pDiscordClient));

    m_eventDispatcher.getEvent("READY")->bind(
        [](const nlohmann::json &eventPacket) {
            std::cout << "user defined ready proc\n";
        });
}

WebsocketHandler::~WebsocketHandler()
{
    std::cout << "Waiting for gateway connection to close\n";
    m_websocketConnectionThread.join();
    delete m_connection;
}

void WebsocketHandler::processWebsocketMessage(const nlohmann::json &json)
{
    const int opcode = json["op"].get<int>();
    //std::cout << json.dump(2) << "\n";
        //std::cout << json.dump();
    switch (opcode)
    {
    case DISPATCH:
    {
        std::string type = json["t"].get<std::string>();
        m_eventDispatcher.distributeEvent(type, json["d"]);


        break;
    }
    case HEARTBEAT:
    {
        break;
    }
    /*
    case IDENTIFY:
    {
        break;
    }
    case STATUS_UPDATE:
    {
        break;
    }
    case VOICE_STATE_UPDATE:
    {
        break;
    }
    case RESUME:
    {
        break;
    }*/
    case RECONNECT:
    {
        break;
    } /*
    case REQUEST_GUILD_MEMBERS:
    {
        break;
    }*/
    case INVALID_SESSION:
    {
        break;
    }
    case HELLO:
    {
        //initialize heartbeat thread
        const int heartbeat_interval = json["d"]["heartbeat_interval"].get<int>();
        std::cout << "heartbeat interval received as  " << heartbeat_interval << "\n";
        m_heartbeater.setInterval(heartbeat_interval);
        m_heartbeater.start(m_ioservice);
        m_connectionStatus = WEBSOCKET_AUTHENTICATING;

        break;
    }
    case HEARTBEAT_ACK:
    {
        receiveHeartbeatACK();

        if (m_connectionStatus == WEBSOCKET_AUTHENTICATING)
        {
            std::cout << "sending identify\n";
            //Send identify packet
            nlohmann::json payload;
            payload["op"] = IDENTIFY;
            payload["d"]["token"] = m_token;
            payload["d"]["properties"]["$os"] = "linux";
            payload["d"]["properties"]["$browser"] = "disco";
            payload["d"]["properties"]["$device"] = "disco";
            payload["d"]["compress"] = false;
            payload["d"]["large_threshold"] = 250;
            payload["d"]["shard"] = {0, 1};
            payload["d"]["presence"]["game"] = nullptr;
            payload["d"]["presence"]["status"] = "online";
            payload["d"]["presence"]["since"] = nullptr;
            payload["d"]["presence"]["afk"] = false;
            m_connection->sendPayload(payload);
        }
        break;
    }
    default:
    {
        //??? wtf happend
        std::cerr << "THIS SHOULD NEVER EVER EVER BE CALLED\n";

        break;
    }
    }
}

bool WebsocketHandler::init()
{
    //connect to websocket.
    m_connectionStatus = WEBSOCKET_CONNECTING;
    std::cout << "Starting Websocket Thread..";
    m_websocketConnectionThread = boost::thread(boost::bind(&WebsocketConnection::connect, m_connection));
    m_connectionStatus = WEBSOCKET_AWAITING_HELLO;
    //wait for identify to be completed.
    std::cout << "Waiting for Websocket Thread to finish identifying..";
    std::unique_lock<std::mutex> lock(m_mutex);
    m_initializationcv.wait(lock);
    std::cout << "done\n";
    return true; //Todo: return if initialized correctly
}

void WebsocketHandler::setReady()
{
    m_connectionStatus = WEBSOCKET_CONNTECTED;
    m_initializationcv.notify_all();
}

void WebsocketHandler::receiveHeartbeatACK()
{
    if (m_heartbeatACK)
        std::cout << "[ERROR]Received HeartbeatACK but didnt send one???\n";

    m_heartbeatACK = true;
}
void WebsocketHandler::resetHeartbeatACK() { m_heartbeatACK = false; }

int WebsocketHandler::getLastSequence() { return m_lastSequence; }
bool WebsocketHandler::getHeartbeatACK() { return m_heartbeatACK; }
WebsocketConnection *WebsocketHandler::getConnection() { return m_connection; }
WebsocketConnectionStatus WebsocketHandler::getConnectionStatus() { return m_connectionStatus; }

} // namespace dppcord