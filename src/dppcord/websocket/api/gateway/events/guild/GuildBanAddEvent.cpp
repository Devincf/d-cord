/**
 * @file GuildBanAddEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:56
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildBanAddEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildBanAddEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "GuildBanAddEvent proc\n";
        //std::cout << eventPacket.dump(4) << '\n';
        Guild& guild = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
        guild.removeUser(tryGetSnowflake("id", eventPacket["user"]));
        m_forwardData.add(eventPacket);
    }

}