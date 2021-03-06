/**
 * @file GuildCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>

namespace dppcord
{
    void GuildCreateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "GuildEvent proc\n";
        Guild& guild = m_pDiscordClient->addGuild(eventPacket);
        m_forwardData.add(guild);
    }

}