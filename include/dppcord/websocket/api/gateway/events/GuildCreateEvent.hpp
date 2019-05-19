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

namespace dppcord
{
    class GuildCreateEvent : public BaseEvent
    {
        using BaseEvent::BaseEvent;
        public:
        void proc(const nlohmann::json& eventPacket);
    };
}

#endif