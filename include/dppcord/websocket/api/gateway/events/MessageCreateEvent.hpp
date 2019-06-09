/**
 * @file MessageCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-25 09:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESSAGECREATEEVENT_HPP
#define MESSAGECREATEEVENT_HPP

#include "BaseEvent.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

namespace dppcord
{
class MessageCreateEvent : public BaseEvent<BaseMessage>
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