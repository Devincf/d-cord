/**
 * @file PresenceUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/PresenceUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>

namespace dppcord
{
    void PresenceUpdateEvent::proc(const rapidjson::Document& eventPacket)
    {
        //std::cout << "PresenceUpdateEvent proc\n";
    }
}