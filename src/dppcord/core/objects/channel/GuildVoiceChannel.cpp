/**
 * @file GuildVoiceChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 02:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/GuildVoiceChannel.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    GuildVoiceChannel::GuildVoiceChannel(){}
    GuildVoiceChannel::~GuildVoiceChannel(){}

    GuildVoiceChannel::GuildVoiceChannel(Guild* pGuild, const nlohmann::json& channeljson):GuildChannel(pGuild, channeljson)
    {
        m_bitrate = tryGetJson<int>("bitrate",channeljson);
        m_userLimit = tryGetJson<int>("user_limit",channeljson);
    }
}