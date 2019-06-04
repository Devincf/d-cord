/**
 * @file ReadyEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/ReadyEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>

namespace dppcord
{
    void ReadyEvent::proc(const rapidjson::Document& eventPacket)
    {
        std::cout << "ReadyEvent proc\n";
        std::cout << eventPacket.dump(4);
        m_pDiscordClient->getWebsocketHandler()->setReady();
        m_pDiscordClient->getDatabase()->query("UPDATE bot_info SET session_id=\"" + eventPacket["session_id"].get<std::string>() + "\",last_sequence=0");
    }
}