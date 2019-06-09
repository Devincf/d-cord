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
#include "dppcord/core/objects/user/BotUser.hpp"
#include <iostream>

namespace dppcord
{
    void ReadyEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ReadyEvent proc\n";
        m_pDiscordClient->getWebsocketHandler().setReady();
        m_pDiscordClient->getBotUser() = BotUser(eventPacket);
        //m_pDiscordClient->getDatabase()->query("UPDATE bot_info SET session_id=\"" + eventPacket["session_id"].get<std::string>() + "\",last_sequence=0");
        m_forwardData.add(eventPacket);
    }
}