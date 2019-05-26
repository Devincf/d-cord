/**
 * @file DmChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 10:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DMCHANNEL_HPP
#define DMCHANNEL_HPP

#include "BaseChannel.hpp"

namespace dppcord
{
    class DmChannel : public BaseChannel
    {
        public:
        DmChannel(const nlohmann::json& channeljson);
        ~DmChannel();

        protected:

        private:
        //Todo: recipients
    };
}

#endif