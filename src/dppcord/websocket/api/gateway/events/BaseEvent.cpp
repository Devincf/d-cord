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
/*
#include <iostream>
namespace dppcord
{
template <typename ...Args>
BaseEvent<Args...>::BaseEvent(DiscordClient *pDiscordClient)
{
    m_pDiscordClient = pDiscordClient;
}
template <typename ...Args>
BaseEvent<Args...>::BaseEvent() {}

template <typename ...Args>
BaseEvent<Args...>::~BaseEvent() {}

template <typename ...Args>
void BaseEvent<Args...>::proc(const nlohmann::json&)
{
    std::cout << "[ERROR]Undefined Event proc has been called\n";
}
template <typename ...Args>
void BaseEvent<Args...>::baseproc(const nlohmann::json &eventPacket)
{
    proc(eventPacket);
    //call user defined func ptr
    if(!m_userFunc.empty()){
        if constexpr (sizeof...(Args) > 0)
        {
            m_forwardData.reset();
            m_userFunc(fromAny<Args>(m_forwardData.next())...);
        }
    }
}
template <typename ...Args>
void BaseEvent<Args...>::bind(const boost::function<void(Args...)> &funcptr)
{
    //TODO: uhh maybe some checking if was already set?
    if(m_userFunc.empty())
        m_userFunc = funcptr;
}
template <typename ...Args>
void BaseEvent<Args...>::bind(const boost::function<void(Args...)> &&funcptr)
{
    //TODO: uhh maybe some checking if was already set?
    if(m_userFunc.empty())
        m_userFunc = funcptr;
}
} // namespace dppcord
*/
