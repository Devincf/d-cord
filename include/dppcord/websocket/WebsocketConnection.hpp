/**
 * @file WebsocketConnection.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 05:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GATEWAY_HPP
#define GATEWAY_HPP

#include <string>

#include <boost/function.hpp>

#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

#include "nlohmann/json.hpp"


using websocketpp::connection_hdl;

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;

typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;
typedef websocketpp::config::asio_tls_client::message_type::ptr message_ptr;


namespace dppcord
{
    class WebsocketConnection
    {
        public:
        /**
         * @brief Construct a new Websocket Connection object
         */
        WebsocketConnection(boost::function<void(nlohmann::json&)> msg_proc);
        /**
         * @brief Destroy the Websocket Connection object
         */
        ~WebsocketConnection();

        /**
         * @brief Connects to the Gateway
         */
        void connect();

        private:
        /**
         * @brief Called on socket initialization by websocketpp
         * @param hdl for connection
         */
        void on_socket_init(const connection_hdl& hdl);
        /**
         * @brief Called on tls connection initialization by websocketpp
         * @param hdl for connection
         * @return context_ptr for tls connection
         */
        context_ptr on_tls_init(const connection_hdl& hdl);
        /**
         * @brief Called if the connection fails to open
         * @param hdl for attempted connection
         */
        void on_fail(const connection_hdl& hdl);
        /**
         * @brief Called once the connection successfully gets established
         * @param hdl for connection
         */
        void on_open(const connection_hdl& hdl);
        /**
         * @brief Called everytime the gateway sends a message to the client
         * @param hdl for connection
         * @param msgptr containing the message
         */
        void on_message(const connection_hdl& hdl, const message_ptr& msgptr);

        /**
         * @brief Client endpoint that connects to the discord gateway
         */
        client m_clientEndpoint;
        /**
         * @brief Handle to current connection
         */
        connection_hdl m_connHdl;

        boost::function<void(nlohmann::json&)> m_msgProc;
    };
}

#endif