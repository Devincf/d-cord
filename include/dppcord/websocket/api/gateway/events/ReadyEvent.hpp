/**
 * @file ReadyEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef READYEVENT_HPP
#define READYEVENT_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class ReadyEvent : public BaseEvent
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a READY dispatch event
     * @param eventPacket json information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif