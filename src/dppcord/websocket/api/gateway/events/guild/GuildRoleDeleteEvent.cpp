/**
 * @file GuildRoleDeleteEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:00
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildRoleDeleteEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildRoleDeleteEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildRoleDeleteEvent proc\n";
        std::cout << eventPacket.dump(4) << '\n';
        Guild& guild = m_pDiscordClient->getGuild(tryGetSnowflake("id", eventPacket));
        m_forwardData.add(guild);
    }

}