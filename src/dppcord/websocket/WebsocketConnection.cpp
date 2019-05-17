/**
 * @file WebsocketConnection.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 06:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/WebsocketConnection.hpp"

namespace dppcord
{

WebsocketConnection::WebsocketConnection(boost::function<void(const nlohmann::json&)> msg_proc): m_msgProc(msg_proc)
{
    m_clientEndpoint.set_access_channels(websocketpp::log::alevel::none);
    m_clientEndpoint.set_error_channels(websocketpp::log::alevel::all);

    m_clientEndpoint.init_asio();

    m_clientEndpoint.set_socket_init_handler(bind(&WebsocketConnection::on_socket_init, this, _1));
    m_clientEndpoint.set_tls_init_handler(bind(&WebsocketConnection::on_tls_init, this, _1));
    m_clientEndpoint.set_fail_handler(bind(&WebsocketConnection::on_fail, this, _1));
    m_clientEndpoint.set_open_handler(bind(&WebsocketConnection::on_open, this, _1));
    m_clientEndpoint.set_message_handler(bind(&WebsocketConnection::on_message, this, _1, _2));
}

WebsocketConnection::~WebsocketConnection()
{
    
}

void WebsocketConnection::connect()
{
    websocketpp::lib::error_code ec;
    const std::string endpoint = "wss://gateway.discord.gg/?v=6&encoding=json";
    auto conn_ptr = m_clientEndpoint.get_connection(endpoint, ec);

    if(ec)
    {
        m_clientEndpoint.get_alog().write(websocketpp::log::alevel::app, ec.message());
        return;
    }

    m_clientEndpoint.connect(conn_ptr);

    m_clientEndpoint.run();

}

void WebsocketConnection::sendPayload(const nlohmann::json& payload)
{
    if(true) //Todo: if connected
    {
        m_clientEndpoint.send(m_connHdl, payload.dump(), websocketpp::frame::opcode::text);
    }
}

void WebsocketConnection::on_socket_init(const connection_hdl& hdl)
{
    //unneeded atm
}

context_ptr WebsocketConnection::on_tls_init(const connection_hdl& hdl)
{
    context_ptr ptr = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);

    try
    {
        ptr->set_options(boost::asio::ssl::context::tlsv1_client);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return ptr;
    
}

void WebsocketConnection::on_fail(const connection_hdl& hdl)
{
    auto conn_ptr = m_clientEndpoint.get_con_from_hdl(hdl);

    std::cerr <<conn_ptr->get_state() << "\n";    
    std::cerr <<conn_ptr->get_local_close_code() << "\n";
    std::cerr <<conn_ptr->get_local_close_reason() << "\n";
    std::cerr <<conn_ptr->get_remote_close_code() << "\n";
    std::cerr <<conn_ptr->get_remote_close_reason() << "\n";
    std::cerr <<conn_ptr->get_ec() << " : " << conn_ptr->get_ec().message() << "\n";
    
}

void WebsocketConnection::on_open(const connection_hdl& hdl)
{
    m_connHdl = hdl;
}

void WebsocketConnection::on_message(const connection_hdl& hdl, const message_ptr& msgptr)
{
    //pass to websockethandler
    nlohmann::json msg = nlohmann::json::parse(msgptr->get_payload());
    m_msgProc(msg);
}


}