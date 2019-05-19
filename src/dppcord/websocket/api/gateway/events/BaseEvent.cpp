/**
 * @file BaseEvent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 06:56
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/BaseEvent.hpp"
#include <iostream>
namespace dppcord
{
BaseEvent::BaseEvent(DiscordClient *pDiscordClient)
{
    m_pDiscordClient = pDiscordClient;
}
BaseEvent::BaseEvent() {}
BaseEvent::~BaseEvent() {}

void BaseEvent::proc(const nlohmann::json &eventPacket)
{
    std::cout << "[ERROR]Undefined Event proc has been called\n";
}

void BaseEvent::baseproc(const nlohmann::json &eventPacket)
{
    proc(eventPacket);
    //call user defined func ptr
    if(!m_userFunc.empty())
        m_userFunc(eventPacket);
}
void BaseEvent::bind(boost::function<void(const nlohmann::json &)> &funcptr)
{
    //Todo: uhh maybe some checking if was already set?
    if(m_userFunc.empty())
        m_userFunc = funcptr;
}
void BaseEvent::bind(boost::function<void(const nlohmann::json &)> &&funcptr)
{
    //Todo: uhh maybe some checking if was already set?
    if(m_userFunc.empty())
        m_userFunc = funcptr;
}
} // namespace dppcord