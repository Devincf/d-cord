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

namespace dppcord
{
WebsocketHandler::WebsocketHandler(const std::string &token) : m_lastSequence(0),m_token(token), m_heartbeater(this, 0)
{
    m_connection = new WebsocketConnection(boost::bind(&WebsocketHandler::processWebsocketMessage, this, boost::placeholders::_1));
}

WebsocketHandler::~WebsocketHandler()
{
    m_websocketConnectionThread.join();
    delete m_connection;
}

void WebsocketHandler::processWebsocketMessage(const nlohmann::json &json)
{
    std::cout << json.dump(2) << "\n";
    const int opcode = json["op"].get<int>();
    switch (opcode)
    {
    case DISPATCH:
    {
        break;
    }
    case HEARTBEAT:
    {
        break;
    }
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
    }
    case RECONNECT:
    {
        break;
    }
    case REQUEST_GUILD_MEMBERS:
    {
        break;
    }
    case INVALID_SESSION:
    {
        break;
    }
    case HELLO:{
        //initialize heartbeat thread
        const int heartbeat_interval = json["d"]["heartbeat_interval"].get<int>();
        std::cout << "heartbeat interval received as  "<< heartbeat_interval << "\n";
        m_heartbeater.setInterval(heartbeat_interval);
        m_heartbeater.start(m_ioservice);
        m_connectionStatus = WEBSOCKET_AUTHENTICATING;
        
        break;
        }
    case HEARTBEAT_ACK:{
        receiveHeartbeatACK();

        if(m_connectionStatus == WEBSOCKET_AUTHENTICATING)
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
            std::cout << payload.dump(2) << "\n";
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
    m_websocketConnectionThread = boost::thread(boost::bind(&WebsocketConnection::connect, m_connection));
    m_connectionStatus = WEBSOCKET_AWAITING_HELLO;
    //wait for identify to be completed.
    std::unique_lock<std::mutex> lock(m_mutex);
    m_initializationcv.wait(lock);
    return true; //Todo: return if initialized correctly
}

void WebsocketHandler::receiveHeartbeatACK() 
{ 
    if(m_heartbeatACK)
        std::cout << "[ERROR]Received HeartbeatACK but didnt send one???\n";    

    m_heartbeatACK = true;
}
void WebsocketHandler::resetHeartbeatACK() { m_heartbeatACK = false; }

int WebsocketHandler::getLastSequence() { return m_lastSequence; }
bool WebsocketHandler::getHeartbeatACK() { return m_heartbeatACK; }
WebsocketConnection *WebsocketHandler::getConnection() { return m_connection; }
WebsocketConnectionStatus WebsocketHandler::getConnectionStatus() { return m_connectionStatus; }

} // namespace dppcord