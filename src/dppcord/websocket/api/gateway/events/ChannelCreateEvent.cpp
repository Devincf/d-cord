/**
 * @file ChannelCreateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 02:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include "dppcord/websocket/api/gateway/events/ChannelCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"

#include "dppcord/core/objects/channel/ChannelTypes.hpp"
#include "dppcord/core/objects/channel/DmChannel.hpp"
#include "dppcord/core/objects/channel/GuildChannel.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void ChannelCreateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ChannelCreateEvent proc\n";
        if(!jsonIsSet("guild_id", eventPacket))
        {
            //dm 
            DmChannel test(eventPacket);
            std::cout << "new dm channel : " << test.getId() << " created\n";
        }else
        {
            auto ptr = reinterpret_cast<GuildChannel&>(m_pDiscordClient->getGuildsHandler().getGuild(tryGetSnowflake("guild_id", eventPacket)).addChannel(eventPacket));
            std::cout << "new guild channel : " << ptr.getName() << " created in guild " << ptr.getGuild().getName();
            m_forwardData.add(ptr);
        }
        
        //m_pDiscordClient->getGuildsHandler().addGuild(new Guild(eventPacket, m_pDiscordClient->getUsersHandler()));
    }
}

/**
 * @brief 
{
 "id": "562591844865671188",
 "last_message_id": "582358770408226836",
 "recipients": [
  {
   "avatar": "8cc5e9b7b50ec12cee0f4179469545a8",
   "discriminator": "6996",
   "id": "142733073262444545",
   "username": "Luminous"
  }
 ],
 "type": 1
}
 * 
 */