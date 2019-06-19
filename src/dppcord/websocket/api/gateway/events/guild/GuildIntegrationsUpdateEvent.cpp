/**
 * @file GuildIntegrationsUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildIntegrationsUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildIntegrationsUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildIntegrationsUpdateEvent proc\n";
        std::cout << eventPacket.dump(4) << '\n';
        Guild& guild = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
        m_forwardData.add(guild);
    }

}