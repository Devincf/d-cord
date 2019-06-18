/**
 * @file WebsocketConnectionStatus.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 09:39
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef WEBSOCKETCONNECTIONSTATUS_HPP
#define WEBSOCKETCONNECTIONSTATUS_HPP

namespace dppcord
{
    enum WebsocketConnectionStatus{
        WEBSOCKET_DISCONNECTED = 0,     //  Websocket connection is currently completly shutdown
        WEBSOCKET_CONNECTING = 1,       //  Websocket connection is currently trying to connect
        WEBSOCKET_AWAITING_HELLO = 2,   //  Websocket connection is waiting for hello message
        WEBSOCKET_AUTHENTICATING = 4,   //  Websocket connection is currently trying to authenticate the client
        WEBSOCKET_CONNTECTED = 8,       //  Websocket is completly connected
        WEBSOCKET_RECONNECTING = 16     //  Websocket is reconnecting
    };
}

#endif