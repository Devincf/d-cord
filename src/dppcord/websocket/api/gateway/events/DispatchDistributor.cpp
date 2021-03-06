/**
 * @file DispatchDistributor.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 06:50
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/websocket/api/gateway/events/DispatchDistributor.hpp"

namespace dppcord
{
DispatchDistributor::DispatchDistributor()
{
}
DispatchDistributor::~DispatchDistributor() {}

bool DispatchDistributor::distributeEvent(const std::string &eventName, const nlohmann::json &eventPacket)
{
    auto it = m_eventMap.find(eventName);
    if (it == m_eventMap.end())
    {
        return false;
    }
    it->second->baseproc(eventPacket);
    return true;
}

bool DispatchDistributor::addEvent(const std::string &eventName, IEvent *pBaseEvent)
{
    auto res = m_eventMap.insert({eventName, std::unique_ptr<IEvent>(pBaseEvent)});
    if (!res.second)
    {
        //already existed
        return false;
    }
    return true;
}

IEvent& DispatchDistributor::getEvent(const std::string &eventName)
{
    auto it = m_eventMap.find(eventName);
    if(it == m_eventMap.end()) throw std::runtime_error("Event"+eventName+" doesnt exist.");
    if(!it->second) throw std::runtime_error("Event is nullptr");
    return *it->second;
}

} // namespace dppcord