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
#include "dppcord/core/objects/channel/BaseChannel.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
    void MessageCreateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "MessageCreateEvent proc\n";
        if(jsonIsSet("guild_id", eventPacket))
        {
            // guild message
            auto channel = m_pDiscordClient->getGuildsHandler()->getGuild(tryGetSnowflake("guild_id", eventPacket))->getChannel(tryGetSnowflake("channel_id", eventPacket));
            BaseMessage m(channel, eventPacket);
            if(m.content() == "!test")
            {
                DiscordEndpoint::sendMessage(channel->getId(), "Hello World!");
            }
        }else
        {
            // dm/groupdm
            //std::cout << eventPacket.dump(1) << '\n';
        }
        
    }

}

/*
{
 "id": "562591844865671188",
 "last_message_id": "582359290858307584",
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


MessageCreateEvent proc
{
 "attachments": [],
 "author": {
  "avatar": "8cc5e9b7b50ec12cee0f4179469545a8",
  "discriminator": "6996",
  "id": "142733073262444545",
  "username": "Luminous"
 },
 "channel_id": "562591844865671188",
 "content": "asd",
 "edited_timestamp": null,
 "embeds": [],
 "id": "582359290858307584",
 "mention_everyone": false,
 "mention_roles": [],
 "mentions": [],
 "nonce": "582359290400997376",
 "pinned": false,
 "timestamp": "2019-05-27T00:07:54.653000+00:00",
 "tts": false,
 "type": 0
}
*/