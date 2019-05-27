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
class DiscordEndpoint
{
public:
    static std::string token;

    static void init(const std::string &itoken);

    static std::string sendMessage(const Snowflake &channelId, const std::string &msg);
};
} // namespace dppcord

#endif