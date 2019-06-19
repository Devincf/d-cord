/**
 * @file GuildMembersChunkEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildMembersChunkEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
void GuildMembersChunkEvent::proc(const nlohmann::json &eventPacket)
{
    /*TODO:
        Used to request all members for a guild or a list of guilds. 
        When initially connecting, the gateway will only send offline members if a guild has less than the large_threshold members (value in the Gateway Identify). 
        If a client wishes to receive additional members, they need to explicitly request them via this operation. 
        The server will send Guild Members Chunk events in response with up to 1000 members per chunk until all members that match the request have been sent.
    */
    std::cout << "GuildMembersChunkEvent proc\n";
    Guild &guild = m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
    for (const auto &member : eventPacket["members"])
    {
        GuildUser *guser = nullptr;

        User *user = m_pDiscordClient->findUser(tryGetSnowflake("id", member["user"]));
        if (user == nullptr)
        {
            guser = new GuildUser(&guild, eventPacket);
            m_pDiscordClient->addUser(static_cast<User *>(guser));
        }
        else
        {
            guser = new GuildUser(&guild, user, eventPacket);
        }
        guild.addUser(guser);
    }
    m_forwardData.add(guild);
}
} // namespace dppcord
