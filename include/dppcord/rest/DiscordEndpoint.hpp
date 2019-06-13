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

    //AUDIT LOG
    static nlohmann::json getGuildAuditLog(const std::string &guildId);

    //CHANNEL API CALLS
    static nlohmann::json getChannel(const std::string &channelId);
    static nlohmann::json modifyChannel(const std::string &channelId, const nlohmann::json &channeldata);
    static nlohmann::json deleteChannel(const std::string &channelId);
    static nlohmann::json getChannelMessages(const std::string &channelId);
    static nlohmann::json getChannelMessage(const std::string &channelId, const std::string &messageId);
    static nlohmann::json sendMessage(const Snowflake &channelId, const std::string &msg);
    static nlohmann::json sendMessageExtended(const Snowflake &channelId, const nlohmann::json &json);
    static bool createReaction(const std::string &channelId, const std::string &msgId, const std::string &emojiNameId);
    static bool deleteOwnReaction(const std::string &channelId, const std::string &messageId, const std::string &emoji);
    static bool deleteUserReaction(const std::string &channelId, const std::string &messageId, const std::string &emoji, const std::string &userId);
    static nlohmann::json getReactions(const std::string &channelId, const std::string &messageId, const std::string &emoji);
    static bool deleteAllReactions(const std::string &channelId, const std::string &messageId);
    static nlohmann::json editMessage(const std::string &channelId, const std::string &messageId, const nlohmann::json& messagedata);
    static bool deleteMessage(const std::string &channel, const std::string &id);
    static bool bulkDeleteMessages(const std::string& channelId, const nlohmann::json& messagearr);
    static bool editChannelPermissions(const std::string& channelId,const std::string& overwriteId, const nlohmann::json& permissiondata);//TODO: test
    static nlohmann::json getChannelInvites(const std::string& channelId);
    static nlohmann::json createChannelInvite(const std::string& channelId, const nlohmann::json& invitedata);
    static bool deleteChannelPermissions(const std::string& channelId,const std::string& overwriteId);//TODO:; test
    static bool triggerTypingIndicator(const std::string& channelId);
    static nlohmann::json getPinnedMessages(const std::string& channelId);
    static bool addPinnedChannelMessage(const std::string& channelId,const std::string& messageId);
    static bool deletePinnedChannelMessage(const std::string& channelId, const std::string& messageId);
    //TODO: check return
    static nlohmann::json groupDmAddRecipient(const std::string& channelId, const std::string& userId);
    //TODO: check return
    static nlohmann::json groupDmRemoveRecipient(const std::string& channelId, const std::string& userId);
    
    //EMOJI API CALLS
    static nlohmann::json listGuildEmojis(const std::string& guildId);
    static nlohmann::json getGuildEmoji(const std::string& guildId, const std::string& emojiId);
    static nlohmann::json createGuildEmoji(const std::string& guildId, const nlohmann::json& emojidata);
    static nlohmann::json modifyGuildEmoji(const std::string& guildId,const std::string& emojiId, const nlohmann::json& emojidata);
    static bool deleteEmoji(const std::string& guildId, const std::string& emojiId);

    //INVITE API CALLS
    static nlohmann::json getInvite(const std::string& inviteCode, bool with_counts = true);
    static nlohmann::json deleteInvite(const std::string& inviteCode);

    //USER API CALLS
    //TODO: implement

    //VOICE API CALLS
    static nlohmann::json listVoiceRegions();

    //WEBHOOK API CALLS
    //TODO: implement


    //GUILD API CALLS
    static nlohmann::json getGuild(const std::string &guildId);
    static nlohmann::json modifyGuild(const std::string &guildId, const nlohmann::json &guilddata);
    static bool deleteGuild(const std::string &guildId);
    static nlohmann::json getGuildChannels(const std::string &guildId);
    static nlohmann::json createGuildChannel(const std::string &guildId, const nlohmann::json &channeldata);
    static bool modifyGuildChannelPositions(const std::string &guildId, const nlohmann::json &channelarr);
    static nlohmann::json getGuildUser(const std::string &guildId, const std::string &userId);
    static nlohmann::json getGuildUserList(const std::string &guildId);
    static bool modifyGuildMember(const std::string &guildId, const std::string &userId, const nlohmann::json &userdata);
    static nlohmann::json modifyCurrentNick(const std::string &guildId, const std::string &nickname);
    static bool addGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId);
    static bool removeGuildMemberRole(const std::string &guildId, const std::string &userId, const std::string &roleId);
    static bool removeGuildMember(const std::string &guildId, const std::string &userId);
    static nlohmann::json getGuildBans(const std::string &guildId);
    static nlohmann::json getGuildBan(const std::string &guildId, const std::string &userId);
    static bool createGuildBan(const std::string &guildId, const std::string &userId, const nlohmann::json &bandata = nlohmann::json());
    static bool removeGuildBan(const std::string &guildId, const std::string &userId);
    static nlohmann::json getGuildRoles(const std::string &guildId);
    static nlohmann::json createGuildRole(const std::string &guildId, const nlohmann::json &roledata);
    static nlohmann::json modifyGuildRolePositions(const std::string &guildId, const nlohmann::json &rolearr);
    static nlohmann::json modifyGuildRole(const std::string &guildId, const std::string &roleId, const nlohmann::json &roledata);
    static bool deleteGuildRole(const std::string &guildId, const std::string &roleId);
    static nlohmann::json getGuildPruneCount(const std::string &guildId, const int days);
    static nlohmann::json beginGuildPrune(const std::string &guildId, const int days, const bool compute_prune_count = false);
    static nlohmann::json getGuildVoiceRegions(const std::string &guildId);
    static nlohmann::json getGuildInvites(const std::string &guildId);
    static nlohmann::json getGuildIntegrations(const std::string &guildId);
    static bool createGuildIntegration(const std::string &guildId, const std::string &type, const std::string &id);
    static bool modifyGuildIntegration(const std::string &guildId, const std::string &integrationId, const nlohmann::json &integrationdata);
    static bool deleteGuildIntegration(const std::string &guildId, const std::string &integrationId);
    static bool syncGuildIntegration(const std::string &guildId, const std::string &integrationId);
    static nlohmann::json getGuildEmbed(const std::string &guildId);
    static nlohmann::json modifyGuildEmbed(const std::string &guildId, const nlohmann::json &embeddata);
    static nlohmann::json getGuildVanityURL(const std::string &guildId);
    static nlohmann::json getGuildWidgetImage(const std::string &guildId, const std::string &&style = "shield");
};
} // namespace dppcord

#endif