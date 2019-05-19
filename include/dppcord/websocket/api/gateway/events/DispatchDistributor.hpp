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
        ~DispatchDistributor();
        DispatchDistributor();

        bool distributeEvent(const std::string& eventName, const nlohmann::json& eventPacket);
        bool addEvent(const std::string& eventName, BaseEvent* pBaseEvent);

        BaseEvent* getEvent(const std::string& eventName);

        private:

        std::map<std::string,std::unique_ptr<BaseEvent>> m_eventMap;
    };
}

#endif