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

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

#include "dppcord/core/objects/channel/BaseChannel.hpp"

namespace dppcord
{
class ChannelCreateEvent : public BaseEvent<BaseChannel>
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