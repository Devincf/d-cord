/**
 * @file GuildCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDCREATEEVENT_HPP
#define GUILDCREATEEVENT_HPP

#include "BaseEvent.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"

namespace dppcord
{
class GuildCreateEvent : public BaseEvent<Guild>
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