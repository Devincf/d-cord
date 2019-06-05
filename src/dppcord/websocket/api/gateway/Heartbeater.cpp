/**
 * @file Heartbeater.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 09:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/Heartbeater.hpp"

#include "nlohmann/json.hpp"

#include "dppcord/websocket/WebsocketHandler.hpp"
#include "dppcord/websocket/api/gateway/GatewayOpCodes.hpp"

namespace dppcord
{
Heartbeater::Heartbeater(WebsocketHandler * const websockethandlerptr, const int interval) : BaseTask(interval, true)
{
    m_websocketHandler = websockethandlerptr;
}

void Heartbeater::proc()
{
    auto status = m_websocketHandler->getConnectionStatus();
    if (status != WEBSOCKET_DISCONNECTED)
    {
        std::cout << "sending heartbeat..";
        if (!m_websocketHandler->getHeartbeatACK() && status == WEBSOCKET_CONNTECTED)
        {
            std::cout << "[ERROR]Heartbeat ACK not received.\n";
        }
        std::cout << "done";
        nlohmann::json payload;
        payload["op"] = GATEWAYOP_HEARTBEAT;
        payload["d"] = m_websocketHandler->getLastSequence();
        m_websocketHandler->getConnection()->sendPayload(payload);
        m_websocketHandler->resetHeartbeatACK();
        this->resetTimer();
    }
    std::cout << '\n';
}
} // namespace dppcord