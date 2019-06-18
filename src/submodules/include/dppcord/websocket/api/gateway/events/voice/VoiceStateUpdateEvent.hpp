/**
 * @file VoiceStateUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef VOICESTATEUPDATEEVENT_HPP
#define VOICESTATEUPDATEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

namespace dppcord
{
class VoiceStateUpdateEvent : public BaseEvent<nlohmann::json>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a READY dispatch event
     * @param eventPacket json information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif