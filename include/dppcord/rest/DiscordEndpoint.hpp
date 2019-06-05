/**
 * @file DiscordEndpoint.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 04:19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISCORDENDPOINT_HPP
#define DISCORDENDPOINT_HPP

#include <string>
#include "dppcord/core/objects/Snowflake.hpp"

namespace dppcord
{

static const std::string apiBase = "https://discordapp.com/api/v6/";

class DiscordEndpoint
{
public:

    static std::string token;

    static void init(const std::string &itoken);

    static const std::string& sendMessage(const Snowflake &channelId, const std::string &msg);
    static const std::string& sendMessageExtended(const Snowflake& channelId, const nlohmann::json& json);
    static const std::string& deleteMessage(const std::string &channel, const std::string &id);
    static const std::string& createReaction(const std::string& channelId, const std::string& msgId, const std::string& emojiNameId);
};
} // namespace dppcord

#endif