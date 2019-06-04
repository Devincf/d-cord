/**
 * @file BaseEvent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 06:55
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BASEEVENT_HPP
#define BASEEVENT_HPP

#include <boost/function.hpp>

#include "nlohmann/json.hpp"

namespace dppcord
{
class DiscordClient;
class BaseEvent
{
public:
    /**
     * @brief Called whenever the event gets received
     * thid should generally never be called by itself. The overwritten member functions should be called.
     * @param json data containing information about the event
     */
    virtual void proc(const nlohmann::json &eventPacket);
    /**
     * @brief base proc which calls the inherited proc and user defined proc if exists
     * @param json data containing information about the event
     */
    void baseproc(const nlohmann::json &eventPacket);
    /**
     * @brief Binds a userdefined function to the event
     * @param rvalue reference function pointer to be bound
     */
    void bind(boost::function<void(const nlohmann::json &)> &&funcptr);
    /**
     * @brief Binds a userdefined function to the event
     * @param reference to function pointer to be bound
     */
    void bind(boost::function<void(const nlohmann::json &)> &funcptr);
    /**
     * @brief Construct a new Base Event object
     * @param pointer to the DiscordClient object
     */
    BaseEvent(DiscordClient *pDiscordClient);
    /**
     * @brief Destroy the Base Event object
     */
    virtual ~BaseEvent();

protected:
    /**
     * @brief Pointer to the DiscordClient object
     */
    DiscordClient *m_pDiscordClient;

private:
    /**
     * @brief Construct a new Base Event object
     */
    BaseEvent();
    /**
     * @brief User defined function pointer to be called after default proc.
     */
    boost::function<void(const nlohmann::json &)> m_userFunc;
};
} // namespace dppcord

#endif