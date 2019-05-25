/**
 * @file MessageCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-25 09:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/MessageCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
    void MessageCreateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "MessageCreateEvent proc\n";
        auto channel = m_pDiscordClient->getGuildsHandler()->getGuild(tryGetSnowflake("guild_id", eventPacket))->getChannel(tryGetSnowflake("channel_id", eventPacket));
        BaseMessage m(channel, eventPacket);
    }

}