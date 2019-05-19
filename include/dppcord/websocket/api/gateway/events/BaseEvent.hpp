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

        virtual void proc(const nlohmann::json& eventPacket);

        void baseproc(const nlohmann::json& eventPacket);

        void bind(boost::function<void(const nlohmann::json&)>&& funcptr);
        void bind(boost::function<void(const nlohmann::json&)>& funcptr);
        
        BaseEvent(DiscordClient* pDiscordClient);
        virtual ~BaseEvent();
        protected:
        DiscordClient* m_pDiscordClient;
        private:
        BaseEvent();
        boost::function<void(const nlohmann::json&)> m_userFunc;
    };
}


#endif