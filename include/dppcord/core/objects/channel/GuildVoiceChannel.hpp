/**
 * @file GuildVoiceChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 02:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDVOICECHANNEL_HPP
#define GUILDVOICECHANNEL_HPP

#include "GuildChannel.hpp"

namespace dppcord
{
class GuildVoiceChannel : public GuildChannel
{
public:
    GuildVoiceChannel();
    ~GuildVoiceChannel();
    GuildVoiceChannel(Guild *pGuild, const nlohmann::json &channeljson);

private:
    /**
     * @brief Maximum bitrate of the voice channel
     */
    int m_bitrate;
    /**
     * @brief Maximum amount of users that can be in this voice channel
     */
    int m_userLimit;
};
} // namespace dppcord

#endif