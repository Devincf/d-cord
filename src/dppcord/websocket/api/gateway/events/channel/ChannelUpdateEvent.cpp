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

namespace dppcord
{
    void ChannelUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ChannelUpdateEvent proc\n";
    }
}