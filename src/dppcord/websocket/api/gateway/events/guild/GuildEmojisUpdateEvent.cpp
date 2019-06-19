/**
 * @file GuildEmojisUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildEmojisUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildEmojisUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildEmojisUpdateEvent proc\n";
        if(eventPacket["emojis"].is_array() && eventPacket["emojis"].size() > 0)
            m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket)).updateEmojis(eventPacket["emojis"]);
        
        m_forwardData.add(eventPacket);
    }

}

/*
{
    "emojis": [
        {
            "animated": false,
            "available": true,
            "id": "546316631023026176",
            "managed": false,
            "name": "emoji",
            "require_colons": true,
            "roles": []
        },
        {
            "animated": false,
            "available": true,
            "id": "588748016513581059",
            "managed": false,
            "name": "urarakasurprised",
            "require_colons": true,
            "roles": []
        }
    ],
    "guild_id": "439065048628068363"
}
 */