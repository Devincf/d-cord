/**
 * @file MessageDeleteEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-05 01:14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/MessageDeleteEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
    void MessageDeleteEvent::proc(const nlohmann::json &eventPacket)
{
    std::cout << "MessageDeleteEvent proc\n";

    std::cout << eventPacket.dump(2) << '\n';
    

    if (jsonIsSet("guild_id", eventPacket))
    {
        // guild message
        auto guild = m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("guild_id", eventPacket));
        guild->removeMessage(tryGetSnowflake("id", eventPacket));
    }
    else
    {
        // dm/groupdm
        //std::cout << eventPacket.dump(1) << '\n';
    }

}
}