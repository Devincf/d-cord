/**
 * @file TypingStartEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TYPINGSTARTEVENT_HPP
#define TYPINGSTARTEVENT_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class TypingStartEvent : public BaseEvent
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a TYPING_START dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif