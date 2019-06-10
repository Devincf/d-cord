/**
 * @file GuildMemberUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:00
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildMemberUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildMemberUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildMemberUpdateEvent proc\n";
        Guild& guild = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("id", eventPacket));
        m_forwardData.add(guild);
    }

}