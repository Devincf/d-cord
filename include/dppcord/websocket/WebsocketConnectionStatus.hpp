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
        WEBSOCKET_DISCONNECTED = 0,
        WEBSOCKET_CONNECTING = 1,
        WEBSOCKET_AWAITING_HELLO = 2,
        WEBSOCKET_AUTHENTICATING = 4,
        WEBSOCKET_CONNTECTED = 8,
        WEBSOCKET_RECONNECTING = 16
    };
}

#endif