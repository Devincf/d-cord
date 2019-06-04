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

#include "dppcord/websocket/api/gateway/events/GuildCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>

namespace dppcord
{
    void GuildCreateEvent::proc(const rapidjson::Document& eventPacket)
    {
        std::cout << "GuildEvent proc\n";
        m_pDiscordClient->getGuildsHandler()->addGuild(new Guild(eventPacket, m_pDiscordClient->getUsersHandler()));
    }

}