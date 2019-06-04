/**
 * @file WebsocketHandler.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 06:37
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef WEBSOCKETHANDLER_HPP
#define WEBSOCKETHANDLER_HPP

#include <memory>
#include <mutex>
#include <condition_variable>

#include <boost/thread.hpp>

#include "WebsocketConnection.hpp"
#include "WebsocketConnectionStatus.hpp"
#include "api/gateway/Heartbeater.hpp"

#include "api/gateway/events/DispatchDistributor.hpp"

namespace dppcord
{
class WebsocketHandler
{
public:
    /**
     * @brief Construct a new Websocket Handler object
     * @param token for communication with the discordapi
     */
    WebsocketHandler(const std::string &token, DiscordClient* pDiscordClient);
    /**
     * @brief Destroy the Websocket Handler object
     */
    ~WebsocketHandler();
    /**
     * @brief Initialize WebsocketHandler
     * @return true if everything worked out
     */
    bool init();
    /**
     * @brief Shuts the Websocket Connection down
     */
    void shutdown();
    /**
     * @brief Used to notify the websocket handler that the gateway connection is now ready
     */
    void setReady();
    /**
     * @brief Called when a HeartbeatACK gets received
     */
    void receiveHeartbeatACK();
    /**
     * @brief Called to reset the last HeartbeatACK
     */
    void resetHeartbeatACK();
    /**
     * @brief Get whether the heartbeat ack boolean is currently set
     * @return boolean whether heartbeat ack was received
     */
    bool getHeartbeatACK();
    /**
     * @brief Get the last sequence
     * @return int last sequence
     */
    int getLastSequence();
    /**
     * @brief Get the gateway connection
     * @return WebsocketConnection* Pointer to the websocket connection object
     */
    WebsocketConnection *getConnection();
    /**
     * @brief Get thec onnection status
     * @return WebsocketConnectionStatus connection status of the gateway
     */
    WebsocketConnectionStatus getConnectionStatus();

    void wait();

private:
    /**
     * @brief Processes a Gateway Message
     * @param json containing the message
     */
    void processWebsocketMessage(const Document &json);
    /**
     * @brief 
     */
    void newConnection();

    /**
     * @brief Last Sequence received by discord
     */
    int m_lastSequence;
    /**
     * @brief Whether the Client received a heartbeat ack since the last heartbeat or not
     */
    bool m_heartbeatACK;
    /**
     * @brief Token for communication with the discordapi
     */
    std::string m_token;
    /**
     * @brief Event dispatcher for incoming dispatch events.
     */
    DispatchDistributor m_eventDispatcher;
    /**
     * @brief Current connection status of the gateway
     */
    WebsocketConnectionStatus m_connectionStatus;
    /**
     * @brief Object to the heartbeater that automatically sends heartbeats every heartbeat interval
     */
    Heartbeater m_heartbeater;
    /**
     * @brief ioservice used for the automatic heartbeater
     */
    boost::asio::io_service m_ioservice;
    /**
     * @brief Thread that runs the websocket connection
     */
    boost::thread m_websocketConnectionThread;
    /**
     * @brief mutex needed for condition variable
     */
    std::mutex m_mutex;
    /**
     * @brief condition variable to determine the completion of the discordapi connection
     */
    std::condition_variable m_initializationcv;
    /**
     * @brief pointer to the discord api gatewayconnection
     */
    //std::unique_ptr<WebsocketConnection> m_connection;
    std::unique_ptr<WebsocketConnection> m_connection;

    /**
     * @brief Pointer to the DiscordClient.
     */
    DiscordClient* m_pClient;
};
} // namespace dppcord

#endif