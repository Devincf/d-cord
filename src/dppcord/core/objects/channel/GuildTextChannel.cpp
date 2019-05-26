/**
 * @file GuildTextChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 01:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/GuildTextChannel.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
GuildTextChannel::GuildTextChannel() {}
GuildTextChannel::~GuildTextChannel() {}

GuildTextChannel::GuildTextChannel(Guild *pGuild, const nlohmann::json &channeljson) : GuildChannel(pGuild, channeljson)
{
    m_topic = tryGetJson<std::string>("topic", channeljson);
    m_rateLimitPerUser = tryGetJson<int>("rate_limit_per_user",channeljson);
}
} // namespace dppcord