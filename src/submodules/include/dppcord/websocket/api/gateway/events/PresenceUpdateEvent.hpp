/**
 * @file PresenceUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PRESENCEUPDATEEVENT_HPP
#define PRESENCEUPDATEEVENT_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class PresenceUpdateEvent : public BaseEvent<nlohmann::json>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a PRESENCE_UPDATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif