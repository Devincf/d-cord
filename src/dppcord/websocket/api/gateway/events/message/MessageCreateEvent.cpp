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

#include "dppcord/websocket/api/gateway/events/message/MessageCreateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/TextChannel.hpp"

#include "dppcord/command/builder/CommandBuilder.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void MessageCreateEvent::proc(const nlohmann::json &eventPacket)
{
    std::cout << "MessageCreateEvent proc\n";

    if (jsonIsSet("guild_id", eventPacket))
    {
        // guild message
        Guild &guild = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
        TextChannel &channel = dynamic_cast<TextChannel &>(guild.getChannel(tryGetSnowflake("channel_id", eventPacket)));

        if (tryGetSnowflake("id", eventPacket["author"]) == 444648378199048214)
        {
            m_forwardData.add(channel.getLastMessage());
            return; // Bot message
        }

        BaseMessage *message = new BaseMessage(channel, eventPacket);
        dppcord::CommandBuilder::tryBuildCommand(*message);
        channel.addMessage(message);
        std::cout << message->str() << '\n';
        m_forwardData.add(*message);
    }
    else
    {
        // dm/groupdm
        //std::cout << eventPacket.dump(1) << '\n';
    }
}

/*REPLACE ABOVE WITH THIS IF ASYNC MESSAGE CREATE PROBLEMS ARISE
this happens whenever the bot sends 2 messages in a row in the same message before the first one can get processed by a message_create event
bot sends 1. message->(last message becomes 1. message)
bot sends 2. message->(last message becomes 2. message)
message_create from 1. message-> last message is 2. message(overwritten.)
message_create from 2. message-> last message is 2. message
void MessageCreateEvent::proc(const nlohmann::json &eventPacket)
{
    std::cout << "MessageCreateEvent proc\n";
    std::cout << eventPacket.dump(4);
    
    if (jsonIsSet("guild_id", eventPacket))
    {
        // guild message
        Guild &guild = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
        TextChannel &channel = dynamic_cast<TextChannel &>(guild.getChannel(tryGetSnowflake("channel_id", eventPacket)));
        auto msgid = tryGetSnowflake("id", eventPacket);
        if(!channel.hasMessage(msgid))
        {
            BaseMessage* message = new BaseMessage(channel, eventPacket);
            
            if (tryGetSnowflake("id", eventPacket["author"]) != 444648378199048214)
                dppcord::CommandBuilder::tryBuildCommand(*message);

            channel.addMessage(message);
            std::cout << message->str() << '\n';
            m_forwardData.add(*message);
        }else
        {
            auto& msg = channel.getMessage(msgid);
            m_forwardData.add(msg);
        }
        
        
    }
    else
    {
        // dm/groupdm
        //std::cout << eventPacket.dump(1) << '\n';
    }
}
 */

} // namespace dppcord

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