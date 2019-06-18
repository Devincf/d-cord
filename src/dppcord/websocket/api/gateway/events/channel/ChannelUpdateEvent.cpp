/**
 * @file ChannelUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include "dppcord/websocket/api/gateway/events/channel/ChannelUpdateEvent.hpp"

#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/channel/ChannelTypes.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"
#include "dppcord/core/objects/channel/GuildChannel.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void ChannelUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ChannelUpdateEvent proc\n";
        int channeltype = eventPacket["type"].get<int>();

        switch(channeltype)
        {
            case CHANNELTYPE_GUILD_TEXT:
            case CHANNELTYPE_GUILD_VOICE:
            case CHANNELTYPE_GUILD_CATEGORY:
            case CHANNELTYPE_GUILD_NEWS:
            case CHANNELTYPE_GUILD_STORE:
            {
                m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket)).updateChannel(eventPacket);
                break;
            }
            case CHANNELTYPE_DM:
            case CHANNELTYPE_GROUP_DM:
            {
                break;
            }
        }
    }
}