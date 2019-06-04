/**
 * @file BaseTask.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 08:55
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/task/BaseTask.hpp"

#include <iostream>

namespace dppcord
{
BaseTask::BaseTask() {}
BaseTask::~BaseTask()
{
    delete m_taskTimer;
    m_taskTimer = nullptr;
}

BaseTask::BaseTask(const int interval) : BaseTask(interval, false)
{
}

BaseTask::BaseTask(const int interval, const bool instantproc) : m_instantproc(instantproc), m_interval{interval}
{
    m_taskTimer = nullptr;
}

void BaseTask::start(boost::asio::io_service &pio)
{
    std::cout << "Starting task with interval" << std::to_string(m_interval.count()) << " and instantproc: " << m_instantproc << "\n";
    if (m_instantproc)
    {
        m_taskTimer = new boost::asio::steady_timer(pio, std::chrono::milliseconds{0});
    }
    else
    {
        m_taskTimer = new boost::asio::steady_timer(pio, m_interval);
    }

    m_taskTimer->async_wait(boost::bind(&BaseTask::proc, this));
    m_thread = boost::thread(boost::bind(&boost::asio::io_service::run, &pio));
}

void BaseTask::stop()
{
    //pthread_cancel(m_thread.native_handle());
    m_taskTimer->cancel();
    m_thread.interrupt();
    std::cout << "Task with interval "<< m_interval.count()<<"stopped\n";
}

void BaseTask::setInterval(const int interval)
{
    if (interval < 0)
        return;
    m_interval = std::chrono::milliseconds{interval};
}

void BaseTask::resetTimer(const int interval)
{
    setInterval(interval);
    m_taskTimer->expires_at(m_taskTimer->expires_at() + m_interval);
    m_taskTimer->async_wait(boost::bind(&BaseTask::proc, this));
}

boost::thread *BaseTask::getThread() { return &m_thread; }
} // namespace dppcord