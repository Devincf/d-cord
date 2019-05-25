/**
 * @file Channel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:54
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/Channel.hpp"
#include "dppcord/core/objects/channel/ChannelTypes.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
Channel::Channel() {}
Channel::~Channel() {}

Channel::Channel(Guild* pGuild, const nlohmann::json &channeljson)
{
    m_guild = pGuild;
    m_id = tryGetSnowflake("id", channeljson);
    m_type = tryGetJson<int>("type",channeljson);
    //guildptr
    m_position = tryGetJson<int>("position",channeljson);
    //permission_overwrites
    m_name = tryGetJson<std::string>("name",channeljson);
    m_topic = tryGetJson<std::string>("topic",channeljson);
    m_nsfw = tryGetJson<bool>("nsfw",channeljson,false);
    m_lastMessageId = tryGetSnowflake("last_message_id",channeljson);
    m_bitrate = tryGetJson<int>("bitrate",channeljson);
    m_userLimit = tryGetJson<int>("user_limit",channeljson);
    m_rateLimitPerUser = tryGetJson<int>("rate_limit_per_user",channeljson);
    //recipients
    m_iconHash = tryGetJson<std::string>("icon",channeljson);
    if(m_type == GROUP_DM)
    {
        //Todo: implement once I split channels
        //m_owner = tryGetSnowflake("owner_id",channeljson);
        //m_application = tryGetSnowflake("application_id",channeljson);
    }
    m_parentId = tryGetSnowflake("parent_id",channeljson);
    //timestamp
}

Snowflake Channel::getId(){return m_id;}
std::string Channel::getName() { return m_name;}
} // namespace dppcord