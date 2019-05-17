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
#include "dppcord/websocket/api/gateway/Heartbeater.hpp"
#include "dppcord/websocket/WebsocketConnectionStatus.hpp"

namespace dppcord
{
class WebsocketHandler
{
public:
    /**
     * @brief Construct a new Websocket Handler object
     * @param token for communication with the discordapi
     */
    WebsocketHandler(const std::string &token);
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
     * @brief Called when a HeartbeatACK gets received
     */
    void receiveHeartbeatACK();
    /**
     * @brief Called when to reset the last HeartbeatACK
     */
    void resetHeartbeatACK();

    bool getHeartbeatACK();
    int getLastSequence();
    WebsocketConnection *getConnection();
    WebsocketConnectionStatus getConnectionStatus();

private:
    /**
     * @brief Processes a Gateway Message
     * @param json containing the message
     */
    void processWebsocketMessage(const nlohmann::json &json);

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
     * @brief Current connection status of the gateway
     */
    WebsocketConnectionStatus m_connectionStatus;
    
    /**
     * @brief Object to the heartbeater that automatically sends heartbeats every heartbeat interval
     */
    Heartbeater m_heartbeater;

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
    WebsocketConnection *m_connection;
};
} // namespace dppcord

#endif