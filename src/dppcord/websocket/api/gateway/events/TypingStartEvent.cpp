/**
 * @file TypingStartEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include "dppcord/websocket/api/gateway/events/TypingStartEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include <iostream>

namespace dppcord
{
    void TypingStartEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "TypingStart proc\n";
    }
}