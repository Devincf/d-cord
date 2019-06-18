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
    /**
     * @brief Construct a new Guild Voice Channel object
     */
    GuildVoiceChannel();
    GuildVoiceChannel(const GuildVoiceChannel&) = default;
    /**
     * @brief Destroy the Guild Voice Channel object
     */
    ~GuildVoiceChannel();
    /**
     * @brief Construct a new Guild Voice Channel object
     * @param pGuild Pointer to the guild this channel belongs to
     * @param channeljson json to use for the channel
     */
    GuildVoiceChannel(Guild *pGuild, const nlohmann::json &channeljson);

    void update(const nlohmann::json& channeldata) override{}
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