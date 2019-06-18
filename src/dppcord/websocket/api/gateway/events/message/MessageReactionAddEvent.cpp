/**
 * @file MessageReactionAddEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 04:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/message/MessageReactionAddEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/channel/TextChannel.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void MessageReactionAddEvent::proc(const nlohmann::json &eventPacket)
{
    //get message
    //if not nullptr procEvent.
    std::cout << "MessageReactionAddEvent proc\n";
    try
    {
        TextChannel& channel = dynamic_cast<TextChannel&>(m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket)).getChannel(tryGetSnowflake("channel_id", eventPacket)));
        auto &msg = channel.getMessage(tryGetSnowflake("message_id", eventPacket));
        std::cout << msg.str() << '\n';
        msg.reactionListener(eventPacket);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    m_forwardData.add(eventPacket);
}

} // namespace dppcord

/*
{
    "channel_id": "550801436238282773",
    "emoji": {
        "animated": false,
        "id": null,
        "name": "🤔"
    },
    "guild_id": "439065048628068363",
    "message_id": "584569209611091980",
    "user_id": "142733073262444545"
}
*/