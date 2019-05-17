/**
 * @file Heartbeater.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 09:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef HEARTBEATER_HPP
#define HEARTBEATER_HPP

#include "dppcord/core/task/BaseTask.hpp"

namespace dppcord
{
    class WebsocketHandler;

    class Heartbeater : public BaseTask
    {
        public:
        Heartbeater(WebsocketHandler* websockethandlerptr, const int interval);
        private:
        void proc();

        WebsocketHandler* m_websocketHandler;
    };
}


#endif