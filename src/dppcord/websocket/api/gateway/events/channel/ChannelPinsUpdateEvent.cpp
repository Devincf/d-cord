/**
 * @file ChannelPinsUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:34
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include "dppcord/websocket/api/gateway/events/channel/ChannelPinsUpdateEvent.hpp"
namespace dppcord
{
    void ChannelPinsUpdateEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ChannelPinsUpdateEvent proc\n";
    }
}