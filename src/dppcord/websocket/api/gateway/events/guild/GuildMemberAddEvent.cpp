/**
 * @file GuildMemberAddEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildMemberAddEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/core/objects/user/GuildUser.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildMemberAddEvent::proc(const nlohmann::json& eventPacket)
    {
        //todo
        std::cout << "GuildMemberAddEvent proc\n";
        GuildUser* guser = nullptr;
        
        Guild& guild =m_pDiscordClient->getGuild(tryGetSnowflake("guild_id", eventPacket));
        User* user = m_pDiscordClient->findUser(tryGetSnowflake("id", eventPacket["user"]));
        if(user == nullptr)
        {
            guser = new GuildUser(&guild,eventPacket);
            m_pDiscordClient->addUser(static_cast<User*>(guser));
        }else
        {
            guser = new GuildUser(&guild,user,eventPacket);
        }
        guild.addUser(guser);
        m_forwardData.add(guser);
    }
}
/*
{
    "deaf": false,
    "guild_id": "301858197713584130",
    "joined_at": "2019-06-18T19:17:00.584947+00:00",
    "mute": false,
    "nick": null,
    "premium_since": null,
    "roles": [],
    "user": {
        "avatar": "7f2cf4400f213fdb1ee151244c452d06",
        "discriminator": "7836",
        "id": "253664664964169730",
        "username": "Matheus Nunes"
    }
}
 */