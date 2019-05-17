/**
 * @file BaseTask.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 08:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BASETASK_HPP
#define BASETASK_HPP

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/thread.hpp>


namespace dppcord
{
    class BaseTask
    {
        public:
        BaseTask(const int interval);
        BaseTask(const int interval, const bool instantproc);
        virtual ~BaseTask();

        void start(boost::asio::io_service& pio);
        void stop();

        boost::thread* getThread();

        void setInterval(const int interval);
        protected:
        virtual void proc() = 0;
        void resetTimer(const int interval = -1);

        bool m_instantproc;
        private:
        BaseTask();

        boost::asio::steady_timer* m_taskTimer;
        std::chrono::milliseconds m_interval;
        boost::thread m_thread;
    };
}

#endif