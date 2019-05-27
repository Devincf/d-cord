/**
 * @file BaseChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:54
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/BaseChannel.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
BaseChannel::BaseChannel() {}
BaseChannel::~BaseChannel() {}

BaseChannel::BaseChannel(const nlohmann::json &channeljson)
{
    m_id = tryGetSnowflake("id", channeljson);
    m_type = tryGetJson<int>("type",channeljson);
    //guildptr
    //permission_overwrites
    //recipients
    m_iconHash = tryGetJson<std::string>("icon",channeljson);
    //timestamp
}
} // namespace dppcord