/**
 * @file VoiceStateUpdateEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/voice/VoiceStateUpdateEvent.hpp"
#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/util/jsonutil.hpp"
#include <iostream>

namespace dppcord
{
void VoiceStateUpdateEvent::proc(const nlohmann::json &eventPacket)
{
    //todo
    std::cout << "VoiceStateUpdateEvent proc\n";
    m_forwardData.add(eventPacket);
}
} // namespace dppcord