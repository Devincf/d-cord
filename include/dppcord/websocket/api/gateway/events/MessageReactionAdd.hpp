/**
 * @file MessageReactionAdd.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 04:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef MESSAGEREACTIONADD_HPP
#define MESSAGEREACTIONADD_HPP

#include "BaseEvent.hpp"

namespace dppcord
{
class MessageReactionAdd : public BaseEvent<nlohmann::json>
{
    using BaseEvent::BaseEvent;

public:
    /**
     * @brief Called when the client receives a MESSAGE_CREATE dispatch event
     * @param json data containing information about the event
     */
    void proc(const nlohmann::json &eventPacket);
};
} // namespace dppcord

#endif