/**
 * @file GuildTextChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 01:10
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDTEXTCHANNEL_HPP
#define GUILDTEXTCHANNEL_HPP

#include "GuildChannel.hpp"

namespace dppcord
{
class BaseMessage;
class GuildTextChannel : public GuildChannel
{
public:
    /**
     * @brief Construct a new Guild Text Channel object
     */
    GuildTextChannel();
    GuildTextChannel(const GuildTextChannel&) = default;
    /**
     * @brief Destroy the Guild Text Channel object
     */
    ~GuildTextChannel();
    /**
     * @brief Construct a new Guild Text Channel object
     * @param pGuild pointer to the Guild this channel belongs to
     * @param channeljson json data used to construct the channel
     */
    GuildTextChannel(Guild* pGuild, const nlohmann::json& channeljson);

protected:
private:
    /**
     * @brief Pointer to the last Message object
     */
    std::shared_ptr<BaseMessage> m_lastMessage;
    /**
     * @brief the channel topic (0-1024 characters)
     */
    std::string m_topic;
    /**
     * @brief amount of seconds a user has to wait before sending another message (0-21600);
     * bots, as well as users with the permission manage_messages or manage_channel, are unaffected
     */
    int m_rateLimitPerUser;
};
} // namespace dppcord

#endif