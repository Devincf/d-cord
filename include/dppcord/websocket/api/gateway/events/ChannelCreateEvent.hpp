/**
 * @file ChannelCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 02:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CHANNELCREATEEVENT_HPP
#define CHANNELCREATEEVENT_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class ChannelCreateEvent : public BaseEvent
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a GUILD_CREATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif