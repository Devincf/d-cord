/**
 * @file ChannelDeleteEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CHANNELDELETEEVENT_HPP
#define CHANNELDELETEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

#include "dppcord/core/objects/channel/BaseChannel.hpp"

namespace dppcord
{
class ChannelDeleteEvent : public BaseEvent<BaseChannel>
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