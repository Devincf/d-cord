/**
 * @file GuildRoleCreateEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10 07:51
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDROLECREATEEVENT_HPP
#define GUILDROLECREATEEVENT_HPP

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"

namespace dppcord
{
class GuildRoleCreateEvent : public BaseEvent<Guild>
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