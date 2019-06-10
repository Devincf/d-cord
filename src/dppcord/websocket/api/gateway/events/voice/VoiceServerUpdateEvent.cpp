/**
 * @file VoiceServerUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/voice/VoiceServerUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void VoiceServerUpdateEvent::proc(const nlohmann::json &eventPacket)
{
    //todo
    std::cout << "VoiceServerUpdateEvent proc\n";
    m_forwardData.add(eventPacket);
}
} // namespace dppcord