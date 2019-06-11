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

    static nlohmann::json sendMessage(const Snowflake &channelId, const std::string &msg);
    static nlohmann::json sendMessageExtended(const Snowflake& channelId, const nlohmann::json& json);
    static bool deleteMessage(const std::string &channel, const std::string &id);
    static bool createReaction(const std::string& channelId, const std::string& msgId, const std::string& emojiNameId);

    static nlohmann::json getGuild(const std::string& guildId);
    static nlohmann::json modifyGuild(const std::string& guildId, const nlohmann::json& guilddata);
    static bool deleteGuild(const std::string& guildId);
    static nlohmann::json getGuildChannels(const std::string& guildId);
    static nlohmann::json createGuildChannel(const std::string& guildId, const nlohmann::json& channeldata);
    static bool modifyGuildChannelPositions(const std::string& guildId, const nlohmann::json& channelarr);
    static nlohmann::json getGuildUser(const std::string& guildId, const std::string& userId);
    static nlohmann::json getGuildUserList(const std::string& guildId);
    static bool modifyGuildMember(const std::string& guildId, const std::string& userId, const nlohmann::json& userdata);
    static nlohmann::json modifyCurrentNick(const std::string& guildId, const std::string& nickname);
    static bool addGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId);
    static bool removeGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId);
    static bool removeGuildMember(const std::string& guildId, const std::string& userId);
    static nlohmann::json getGuildBans(const std::string& guildId);
    static nlohmann::json getGuildBan(const std::string& guildId, const std::string& userId);
    static bool createGuildBan(const std::string& guildId, const std::string& userId, const nlohmann::json& bandata = nlohmann::json());
    static bool removeGuildBan(const std::string& guildId, const std::string& userId);

    static nlohmann::json getGuildRoles(const std::string& guildId);
    static nlohmann::json createGuildRole(const std::string& guildId, const nlohmann::json& roledata);
    static nlohmann::json modifyGuildRolePositions(const std::string& guildId, const nlohmann::json& rolearr);
    static nlohmann::json modifyGuildRole(const std::string& guildId, const nlohmann::json& roledata);
    static bool removeGuildRole(const std::string& guildId, const std::string& roleId);
    static nlohmann::json getGuildPruneCount(const std::string& guildId, const int days);
    static nlohmann::json beginGuildPrune(const std::string& guildId, const int days, const bool compute_prune_count = false);
    static nlohmann::json getGuildVoiceRegions(const std::string& guildId);
    static nlohmann::json getGuildInvites(const std::string& guildId);
    static nlohmann::json getGuildIntegrations(const std::string& guildId);
    static bool createGuildIntegration(const std::string& guildId, const std::string& type, const std::string& id);
    static bool modifyGuildIntegration(const std::string& guildId, const nlohmann::json& integrationdata);
    static bool deleteGuildIntegration(const std::string& guildId, const std::string& integrationId);
    static bool syncGuildIntegration(const std::string& guildId, const std::string& integrationId);
    static nlohmann::json getGuildEmbed(const std::string& guildId);
    static nlohmann::json modifyGuildEmbed(const std::string& guildId, const nlohmann::json& embeddata);
    static nlohmann::json getGuildVanityURL(const std::string& guildId);
    static nlohmann::json getGuildWidgetImage(const std::string& guildId, const std::string&& style = "shield");

};
} // namespace dppcord

#endif