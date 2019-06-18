/**
 * @file ChannelDeleteEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/channel/ChannelDeleteEvent.hpp"
#include <iostream>


#include "dppcord/core/client/DiscordClient.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void ChannelDeleteEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ChannelDeleteEvent proc\n";
        auto guildId = tryGetSnowflake("guild_id", eventPacket);
        if(guildId != 0)
        {
            auto channelId = tryGetSnowflake("id", eventPacket);
            m_pDiscordClient->getGuild(guildId).removeChannel(channelId);
        }
    }
}

/*
{
    "guild_id": "439065048628068363",
    "id": "590514513837817858",
    "last_message_id": null,
    "name": "delete",
    "nsfw": false,
    "parent_id": "439065048628068364",
    "permission_overwrites": [
        {
            "allow": 0,
            "deny": 805776464,
            "id": "439065048628068363",
            "type": "role"
        }
    ],
    "position": 16,
    "rate_limit_per_user": 0,
    "topic": null,
    "type": 0
}
 */