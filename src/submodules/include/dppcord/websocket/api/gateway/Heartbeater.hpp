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
    /**
     * @brief Construct a new Heartbeater object
     * @param websockethandlerptr pointer to the websocket handler
     * @param interval Heartbeat interval
     */
    Heartbeater(WebsocketHandler * const websockethandlerptr, const int interval);

private:
    /**
     * @brief Called each heartbeat interval
     */
    void proc();
    /**
     * @brief Pointer to the websocket handler
     */
    WebsocketHandler *m_websocketHandler;
};
} // namespace dppcord

#endif