/**
 * @file DispatchDistributor.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 06:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISPATCHDISTRIBUTOR_HPP
#define DISPATCHDISTRIBUTOR_HPP

#include <string>
#include <map>
#include <memory>

#include "BaseEvent.hpp"

namespace dppcord
{
class DispatchDistributor
{
public:
    /**
     * @brief Destroy the Dispatch Distributor object
     */
    ~DispatchDistributor();
    /**
     * @brief Construct a new Dispatch Distributor object
     */
    DispatchDistributor();
    /**
     * @brief Distributes events
     * @param name of event to be called
     * @param json data about the event
     * @return Whether the event was found or not
     */
    bool distributeEvent(const std::string &eventName, const Document &eventPacket);
    /**
     * @brief Adds an event into the dispatch event map
     * @param name of the event to be added
     * @param pointer to the event 
     * @return Whether the event didnt exist in the map before  
     */
    bool addEvent(const std::string &eventName, BaseEvent *pBaseEvent);
    /**
     * @brief Get the pointer of a event with a name
     * @param eventName of the event 
     * @return pointer of the event if exists, nullptr if eventName wasnt found
     */
    BaseEvent *getEvent(const std::string &eventName);

private:
    /**
     * @brief Map containing all dispatch events
     */
    std::map<std::string, std::unique_ptr<BaseEvent>> m_eventMap;
};
} // namespace dppcord

#endif