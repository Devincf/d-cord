/**
 * @file GuildDeleteEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:58
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildDeleteEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildDeleteEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildDeleteEvent proc\n";
        Guild& guild = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("id", eventPacket));
        m_forwardData.add(guild);
    }

}