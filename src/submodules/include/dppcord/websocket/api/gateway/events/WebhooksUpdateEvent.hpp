/**
 * @file WebhooksUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 08:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef WEBHOOKSUPDATEEVENT_HPP
#define WEBHOOKSUPDATEEVENT_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class WebhooksUpdateEvent : public BaseEvent<nlohmann::json>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a CHANNEL_CREATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif