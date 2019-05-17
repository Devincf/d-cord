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


private:

    /**
     * @brief Processes a Gateway Message
     * @param json containing the message
     */
    void processWebsocketMessage(const nlohmann::json &json);

    /**
     * @brief Token for communication with the discordapi
     */
    std::string m_token;

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
    WebsocketConnection* m_connection;
};
} // namespace dppcord

#endif