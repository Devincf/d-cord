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

#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/database/SQLiteDatabase.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
WebsocketHandler::WebsocketHandler(DiscordClient *pDiscordClient) : m_lastSequence(0), m_heartbeater(this, 0)
{
    m_pClient = pDiscordClient;

    m_eventDispatcher.addEvent("READY", new ReadyEvent(pDiscordClient));
    m_eventDispatcher.addEvent("RESUMED", new ResumeEvent(pDiscordClient));
    m_eventDispatcher.addEvent("CHANNEL_CREATE", new ChannelCreateEvent(pDiscordClient));
    m_eventDispatcher.addEvent("CHANNEL_UPDATE", new ChannelUpdateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("CHANNEL_DELETE", new ChannelDeleteEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("CHANNEL_PINS_UPDATE", new ChannelPinsUpdateEvent(pDiscordClient));
    m_eventDispatcher.addEvent("GUILD_CREATE", new GuildCreateEvent(pDiscordClient));                
    m_eventDispatcher.addEvent("GUILD_UPDATE", new GuildUpdateEvent(pDiscordClient)); //Untested
    m_eventDispatcher.addEvent("GUILD_DELETE", new GuildDeleteEvent(pDiscordClient)); //Untested
    m_eventDispatcher.addEvent("GUILD_BAN_ADD", new GuildBanAddEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("GUILD_BAN_REMOVE", new GuildBanRemoveEvent(pDiscordClient)); //Untested
    m_eventDispatcher.addEvent("GUILD_EMOJIS_UPDATE", new GuildEmojisUpdateEvent(pDiscordClient));  //Untested
    m_eventDispatcher.addEvent("GUILD_INTEGRATIONS_UPDATE", new GuildIntegrationsUpdateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("GUILD_MEMBER_ADD", new GuildMemberAddEvent(pDiscordClient)); //Untested
    m_eventDispatcher.addEvent("GUILD_MEMBER_REMOVE", new GuildMemberRemoveEvent(pDiscordClient));  //Untested
    m_eventDispatcher.addEvent("GUILD_MEMBER_UPDATE", new GuildMemberUpdateEvent(pDiscordClient));  //Untested
    m_eventDispatcher.addEvent("GUILD_MEMBERS_CHUNK", new GuildMembersChunkEvent(pDiscordClient));  //Untested
    m_eventDispatcher.addEvent("GUILD_ROLE_CREATE", new GuildRoleCreateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("GUILD_ROLE_UPDATE", new GuildRoleUpdateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("GUILD_ROLE_DELETE", new GuildRoleDeleteEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("MESSAGE_CREATE", new MessageCreateEvent(pDiscordClient));
    m_eventDispatcher.addEvent("MESSAGE_UPDATE", new MessageUpdateEvent(pDiscordClient)); // Untested
    m_eventDispatcher.addEvent("MESSAGE_DELETE", new MessageDeleteEvent(pDiscordClient));
    m_eventDispatcher.addEvent("MESSAGE_DELETE_BULK", new MessageDeleteBulkEvent(pDiscordClient)); // Untested
    m_eventDispatcher.addEvent("MESSAGE_REACTION_ADD", new MessageReactionAddEvent(pDiscordClient));
    m_eventDispatcher.addEvent("MESSAGE_REACTION_REMOVE", new MessageReactionRemoveEvent(pDiscordClient));        //Untested
    m_eventDispatcher.addEvent("MESSAGE_REACTION_REMOVE_ALL", new MessageReactionRemoveAllEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("PRESENCE_UPDATE", new PresenceUpdateEvent(pDiscordClient));
    m_eventDispatcher.addEvent("TYPING_START", new TypingStartEvent(pDiscordClient));
    m_eventDispatcher.addEvent("USER_UPDATE", new UserUpdateEvent(pDiscordClient));                 //Untested
    m_eventDispatcher.addEvent("VOICE_STATE_UPDATE", new VoiceStateUpdateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("VOICE_SERVER_UPDATE", new VoiceServerUpdateEvent(pDiscordClient));//Untested
    m_eventDispatcher.addEvent("WEBHOOKS_UPDATE", new WebhooksUpdateEvent(pDiscordClient));//Untested



    /*m_eventDispatcher.getEvent("READY").bind(
        [](const nlohmann::json &eventPacket) {
            //std::cout << "user defined ready proc\n";
        });*/
    static_cast<ReadyEvent&>(m_eventDispatcher.getEvent("READY")).bind(
        [](const nlohmann::json &eventPacket) {
            std::cout << "user defined ready proc\n";
        });
}

WebsocketHandler::~WebsocketHandler()
{
}

void WebsocketHandler::processWebsocketMessage(const nlohmann::json &json)
{
    const int opcode = json["op"].get<int>();

    //std::cout << json.dump(2) << '\n';

    if (jsonIsSet("s", json))
    {
        m_lastSequence = json["s"].get<int>();
    }

    switch (opcode)
    {
    case GATEWAYOP_DISPATCH:
    {
        std::string type = json["t"].get<std::string>();
        if (!m_eventDispatcher.distributeEvent(type, json["d"]))
        {
            std::cout << "[ERROR] Couldnt distribute Dispatch Event \"" << type << "\"\n";
        }
        break;
    }
    case GATEWAYOP_HEARTBEAT:
    {
        break;
    }
    /*
    case GATEWAYOP_IDENTIFY:
    {
        break;
    }
    case GATEWAYOP_STATUS_UPDATE:
    {
        break;
    }
    case GATEWAYOP_VOICE_STATE_UPDATE:
    {
        break;
    }*/
    case GATEWAYOP_RESUME:
    {
        std::cout << json.dump(2) << '\n';
        break;
    }
    case GATEWAYOP_RECONNECT:
    {
        break;
    } /*
    case GATEWAYOP_REQUEST_GUILD_MEMBERS:
    {
        break;
    }*/
    case GATEWAYOP_INVALID_SESSION:
    {
        if (m_connectionStatus == WEBSOCKET_RECONNECTING)
        {
            int randomNumber = (rand() % 5) + 1;
            std::cout << "Resume failed, sending fresh Identify after " + std::to_string(randomNumber) + " seconds\n";
            std::this_thread::sleep_for(std::chrono::seconds(randomNumber));
            sendIdentify();
        }
        break;
    }
    case GATEWAYOP_HELLO:
    {
        //initialize heartbeat thread
        const int heartbeat_interval = json["d"]["heartbeat_interval"].get<int>();
        std::cout << "heartbeat interval received as  " << heartbeat_interval << "\n";
        m_heartbeater.setInterval(heartbeat_interval);
        m_heartbeater.start(m_ioservice);

        auto res = m_pClient->getDatabase().query("SELECT session_id, last_sequence FROM bot_info").at(0);

        m_connectionStatus = WEBSOCKET_RECONNECTING;
        nlohmann::json payload;
        payload["op"] = GATEWAYOP_RESUME;
        payload["d"]["token"] = m_token;
        payload["d"]["session_id"] = res["session_id"];
        payload["d"]["seq"] = std::stoi(res["last_sequence"]);
        m_connection->sendPayload(payload);
        //std::cout << payload.dump(4);

        break;
    }
    case GATEWAYOP_HEARTBEAT_ACK:
    {
        receiveHeartbeatACK();
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

void WebsocketHandler::sendIdentify()
{
    m_connectionStatus = WEBSOCKET_AUTHENTICATING;
    std::cout << "sending identify\n";
    //Send identify packet
    nlohmann::json payload;
    payload["op"] = GATEWAYOP_IDENTIFY;
    payload["d"]["token"] = m_token;
    payload["d"]["properties"]["$os"] = "linux";
    payload["d"]["properties"]["$browser"] = "dppcord";
    payload["d"]["properties"]["$device"] = "dppcord";
    payload["d"]["compress"] = false;
    payload["d"]["large_threshold"] = 250;
    payload["d"]["shard"] = {0, 1};
    payload["d"]["presence"]["game"] = nullptr;
    payload["d"]["presence"]["status"] = "online";
    payload["d"]["presence"]["since"] = nullptr;
    payload["d"]["presence"]["afk"] = false;
    m_connection->sendPayload(payload);
}

const bool WebsocketHandler::init()
{
    //connect to websocket.
    m_connectionStatus = WEBSOCKET_CONNECTING;
    std::cout << "Starting Websocket Thread..";
    //resetHeartbeatACK();
    m_connection = std::make_unique<WebsocketConnection>(boost::bind(&WebsocketHandler::processWebsocketMessage, this, boost::placeholders::_1));
    m_websocketConnectionThread = boost::thread(&WebsocketConnection::connect, m_connection.get(), &m_initializationcv);
    m_connectionStatus = WEBSOCKET_AWAITING_HELLO;
    //wait for identify to be completed.
    std::cout << "Waiting for Websocket Thread to finish identifying..";
    std::cout << "done\n";
    return true; //TODO: return if initialized correctly
}

void WebsocketHandler::shutdown()
{
    if (m_connectionStatus != WEBSOCKET_DISCONNECTED)
    {
        m_connectionStatus = WEBSOCKET_DISCONNECTED;
        m_heartbeater.stop();
        m_connection->shutdown();

        std::string q = "UPDATE bot_info SET last_sequence=" + std::to_string(m_lastSequence) + ", session_id=\"" + m_pClient->getBotUser().getSessionId() + '\"';
        m_pClient->getDatabase().query(q);
        m_websocketConnectionThread.join();
        std::cout << "shutdown complete";
    }
}

void WebsocketHandler::wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_initializationcv.wait(lock);
}

void WebsocketHandler::setReady()
{
    m_connectionStatus = WEBSOCKET_CONNTECTED;
}

void WebsocketHandler::receiveHeartbeatACK()
{
    if (m_heartbeatACK)
        std::cout << "[ERROR]Received HeartbeatACK but didnt send one???\n";

    m_heartbeatACK = true;
}
void WebsocketHandler::resetHeartbeatACK() { m_heartbeatACK = false; }

void WebsocketHandler::setToken(const std::string& token){m_token = token;}

DispatchDistributor &WebsocketHandler::getDispatcher() { return m_eventDispatcher; }
const int WebsocketHandler::getLastSequence() const { return m_lastSequence; }
const bool WebsocketHandler::getHeartbeatACK() const { return m_heartbeatACK; }
WebsocketConnection *WebsocketHandler::getConnection() const { return m_connection.get(); }
const WebsocketConnectionStatus WebsocketHandler::getConnectionStatus() const { return m_connectionStatus; }

} // namespace dppcord