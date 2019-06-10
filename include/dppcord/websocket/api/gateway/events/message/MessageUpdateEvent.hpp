/**
 * @file MessageUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef MESSAGEUPDATEEVENT_HPP
#define MESSAGEUPDATEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

namespace dppcord
{
class MessageUpdateEvent : public BaseEvent<nlohmann::json>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a MESSAGE_CREATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif