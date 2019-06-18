/**
 * @file MessageReactionAddEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 04:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef MESSAGEREACTIONADDEVENT_HPP
#define MESSAGEREACTIONADDEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

namespace dppcord
{
class MessageReactionAddEvent : public BaseEvent<nlohmann::json>
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