/**
 * @file ReadyEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/ReadyEvent.hpp"
#include <iostream>

namespace dppcord
{
    void ReadyEvent::proc(const nlohmann::json& eventPacket)
    {
        std::cout << "ReadyEvent proc\n";
    }
}