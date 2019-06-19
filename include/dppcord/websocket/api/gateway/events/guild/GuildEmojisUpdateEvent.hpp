/**
 * @file GuildEmojisUpdateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:49
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef GUILDEMOJISUPDATEEVENT_HPP
#define GUILDEMOJISUPDATEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"

namespace dppcord
{
class GuildEmojisUpdateEvent : public BaseEvent<nlohmann::json>
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