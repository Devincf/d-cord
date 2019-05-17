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


namespace dppcord
{
    WebsocketHandler::WebsocketHandler(const std::string& token): m_token(token)
    {
        std::cout << "construct websocket handler";
        m_connection = new WebsocketConnection(boost::bind(&WebsocketHandler::processWebsocketMessage, this, boost::placeholders::_1));
    }

    WebsocketHandler::~WebsocketHandler()
    {
        m_websocketConnectionThread.join();
        delete m_connection;
    }

    void WebsocketHandler::processWebsocketMessage(const nlohmann::json& json)
    {
        std::cout << json.dump(2) << "\n";
    }

    bool WebsocketHandler::init()
    {
        std::cout << "init websocket handler";
        //connect to websocket.
        m_websocketConnectionThread = boost::thread(boost::bind(&WebsocketConnection::connect, m_connection));
        //wait for identify to be completed.
        std::unique_lock<std::mutex> lock(m_mutex);
        m_initializationcv.wait(lock);
        return true;//Todo: return if initialized correctly
    }
}