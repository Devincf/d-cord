#include "dppcord/websocket/WebsocketConnection.hpp"

namespace dppcord
{

WebsocketConnection::WebsocketConnection(const boost::function<void(const nlohmann::json &)>& msg_proc) : m_msgProc(msg_proc)
{
    m_clientEndpoint.set_access_channels(websocketpp::log::alevel::none);
    m_clientEndpoint.set_error_channels(websocketpp::log::alevel::all);

    m_clientEndpoint.init_asio();

    m_clientEndpoint.set_socket_init_handler(bind(&WebsocketConnection::on_socket_init, this, _1));
    m_clientEndpoint.set_tls_init_handler(bind(&WebsocketConnection::on_tls_init, this, _1));
    m_clientEndpoint.set_fail_handler(bind(&WebsocketConnection::on_fail, this, _1));
    m_clientEndpoint.set_open_handler(bind(&WebsocketConnection::on_open, this, _1));
    m_clientEndpoint.set_message_handler(bind(&WebsocketConnection::on_message, this, _1, _2));
    m_clientEndpoint.set_close_handler(bind(&WebsocketConnection::on_close, this, _1));
}

WebsocketConnection::~WebsocketConnection()
{
}

void WebsocketConnection::connect(std::condition_variable * const cv)
{
    websocketpp::lib::error_code ec;
    const std::string endpoint = "wss://gateway.discord.gg/?v=6&encoding=json";
    auto conn_ptr = m_clientEndpoint.get_connection(endpoint, ec);

    if (ec)
    {
        m_clientEndpoint.get_alog().write(websocketpp::log::alevel::app, ec.message());
        return;
    }
    try
    {
        m_clientEndpoint.connect(conn_ptr);

        m_running = true;
        m_clientEndpoint.run();
    }
    catch (const websocketpp::exception &e)
    {
        std::cout << "websocketpp::exception(WebsocketConnecction::connect): "<<e.what() << '\n';
    }catch(const std::runtime_error& e)
    {
        std::cout << "std::runtime_error(WebsocketConnecction::connect): " <<e.what() << '\n';
    }

    m_running = false;
    cv->notify_all();
}

void WebsocketConnection::shutdown()
{
    if (m_running)
    {
        m_clientEndpoint.pause_reading(m_connHdl);
        m_clientEndpoint.close(m_connHdl, websocketpp::close::status::going_away, "disconnect");
    }
}

void WebsocketConnection::sendPayload(const nlohmann::json &payload)
{
    if (m_running) //TODO: if connected
    {
        m_clientEndpoint.send(m_connHdl, payload.dump(), websocketpp::frame::opcode::text);
    }
}

void WebsocketConnection::on_socket_init(const connection_hdl &hdl)
{
    //unneeded atm
}

context_ptr WebsocketConnection::on_tls_init(const connection_hdl &hdl)
{
    context_ptr ptr = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);

    try
    {
        ptr->set_options(boost::asio::ssl::context::tlsv1_client);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return ptr;
}

void WebsocketConnection::on_fail(const connection_hdl &hdl)
{
    auto conn_ptr = m_clientEndpoint.get_con_from_hdl(hdl);

    std::cerr << conn_ptr->get_state() << "\n";
    std::cerr << conn_ptr->get_local_close_code() << "\n";
    std::cerr << conn_ptr->get_local_close_reason() << "\n";
    std::cerr << conn_ptr->get_remote_close_code() << "\n";
    std::cerr << conn_ptr->get_remote_close_reason() << "\n";
    std::cerr << conn_ptr->get_ec() << " : " << conn_ptr->get_ec().message() << "\n";
}

void WebsocketConnection::on_close(const connection_hdl &hdl)
{
    client::connection_ptr con = m_clientEndpoint.get_con_from_hdl(hdl);
    std::stringstream s;
    s << "close code: " << con->get_remote_close_code() << " ("
      << websocketpp::close::status::get_string(con->get_remote_close_code())
      << "), close reason: " << con->get_remote_close_reason();
    std::cout << s.str() << '\n';
}

void WebsocketConnection::on_open(const connection_hdl &hdl)
{
    m_connHdl = hdl;
}

void WebsocketConnection::on_message(const connection_hdl &hdl, const message_ptr &msgptr)
{
    //pass to websockethandler
    nlohmann::json msg = nlohmann::json::parse(msgptr->get_payload());
    m_msgProc(msg);
}

} // namespace dppcord