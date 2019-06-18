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

#include "EventForwardData.hpp"


namespace dppcord
{
class IEvent
{
public:
    virtual ~IEvent() = default;
    virtual void baseproc(const nlohmann::json &eventPacket) = 0;
};

class DiscordClient;
template <typename... Args>
class BaseEvent : public IEvent
{
public:
    /**
     * @brief Called whenever the event gets received
     * thid should generally never be called by itself. The overwritten member functions should be called.
     * @param json data containing information about the event
     */
    virtual void proc(const nlohmann::json &eventPacket)
    {
        std::cout << "[ERROR]Undefined Event proc has been called\n";
    }
    /**
     * @brief base proc which calls the inherited proc and user defined proc if exists
     * @param json data containing information about the event
     */
    void baseproc(const nlohmann::json &eventPacket)
    {
        m_forwardData.reset();
        proc(eventPacket);
        //call user defined func ptr
        if (!m_userFunc.empty())
        {
            if constexpr (sizeof...(Args) > 0)
            {
                m_forwardData.prepare();
                m_userFunc(std::move(fromAny<Args>(m_forwardData.next())...));
            }
        }
    }
    /**
     * @brief Binds a userdefined function to the event
     * @param rvalue reference function pointer to be bound
     */
    void bind(const boost::function<void(const Args&...)> &&funcptr)
    {
        //TODO: uhh maybe some checking if was already set?
        if (m_userFunc.empty())
            m_userFunc = funcptr;
    }
    /**
     * @brief Binds a userdefined function to the event
     * @param reference to function pointer to be bound
     */
    void bind(const boost::function<void(const Args&...)> &funcptr)
    {
        //TODO: uhh maybe some checking if was already set?
        if (m_userFunc.empty())
            m_userFunc = funcptr;
    }
    /**
     * @brief Construct a new Base Event object
     * @param pointer to the DiscordClient object
     */
    BaseEvent(DiscordClient *pDiscordClient)
    {
        m_pDiscordClient = pDiscordClient;
    }
    /**
     * @brief Destroy the Base Event object
     */
    virtual ~BaseEvent() {}

protected:
    /**
     * @brief Pointer to the DiscordClient object
     */
    DiscordClient *m_pDiscordClient;
    
    EventForwardData<sizeof...(Args)> m_forwardData;

private:
    /**
     * @brief Construct a new Base Event object
     */
    BaseEvent() {}
    /**
     * @brief User defined function pointer to be called after default proc.
     */
    boost::function<void(const Args&...)> m_userFunc;

};
} // namespace dppcord
#include "../src/dppcord/websocket/api/gateway/events/BaseEvent.cpp"

#endif