/**
 * @file DmChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 10:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/DmChannel.hpp"

namespace dppcord
{
    DmChannel::DmChannel(const nlohmann::json& channeljson):BaseChannel(channeljson)
    {

    }

    DmChannel::~DmChannel(){}
}