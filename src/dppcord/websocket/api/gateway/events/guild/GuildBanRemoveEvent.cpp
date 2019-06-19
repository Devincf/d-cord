/**
 * @file GuildBanRemoveEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:58
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/guild/GuildBanRemoveEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    void GuildBanRemoveEvent::proc(const nlohmann::json& eventPacket)
    {
        //TODO: test
        std::cout << "GuildBanRemoveEvent proc\n";
        std::cout << eventPacket.dump(4) << '\n';
        m_forwardData.add(eventPacket);
    }
}

/*
{
    "guild_id": "439065048628068363",
    "user": {
        "avatar": "41e1b45d0abb1446ffc39a7a4057f01c",
        "discriminator": "5014",
        "id": "396159492238344213",
        "username": "Snow Neko<--3412"
    }
}
 */