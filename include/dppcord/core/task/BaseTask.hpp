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
        /**
         * @brief Construct a new Base Task object
         * @param interval wait time during each execution of the task
         */
        BaseTask(const int interval);
        /**
         * @brief Construct a new Base Task object
         * @param interval wait time during each execution of the task
         * @param instantproc whether the task should be executed instantly or wait 1 interval first
         */
        BaseTask(const int interval, const bool instantproc);
        /**
         * @brief Destroy the Base Task object
         */
        virtual ~BaseTask();
        /**
         * @brief Starts the task 
         * @param pio reference to a io_service object for the task
         */
        void start(boost::asio::io_service& pio);
        /**
         * @brief Stop the thread which runs the task
         */
        void stop();
        /**
         * @brief Get the task thread 
         * @return boost::thread* pointer to the thread used for the task
         */
        boost::thread* getThread();
        /**
         * @brief Set the task interval
         * @param interval new interval does nothing if -1 is passed
         */
        void setInterval(const int interval);
        protected:
        /**
         * @brief Called every iteration of the task
         */
        virtual void proc() = 0;
        /**
         * @brief Resets the timer with a given interval
         * @param interval new interval, if negative continues to use old interval
         */
        void resetTimer(const int interval = -1);
        /**
         * @brief Whether the task should be instantly executed 
         */
        bool m_instantproc;
        private:
        /**
         * @brief Construct a new Base Task object
         */
        BaseTask();
        /**
         * @brief Pointer to the timer object for the task
         */
        boost::asio::steady_timer* m_taskTimer;
        /**
         * @brief interval between each task execution
         */
        std::chrono::milliseconds m_interval;
        /**
         * @brief Thread in which the task is being executed in
         */
        boost::thread m_thread;
    };
}

#endif