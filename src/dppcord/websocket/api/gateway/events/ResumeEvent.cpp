/**
 * @file ResumeEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 02:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include "dppcord/websocket/api/gateway/events/ResumeEvent.hpp"

namespace dppcord
{
    void ResumeEvent::proc(const rapidjson::Document& eventPacket)
    {
        std::cout << "ResumeEvent proc\n";
        std::cout << eventPacket.dump(4) << '\n';
    }
}