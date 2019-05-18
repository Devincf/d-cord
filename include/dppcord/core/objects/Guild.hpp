/**
 * @file Guild.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 07:38
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILD_HPP
#define GUILD_HPP

#include "Snowflake.hpp"

namespace dppcord
{
class Guild
{
public:
private:
    /**
     * @brief Guild id 
     */
    Snowflake m_id;
    /**
     * @brief Guild name
     */
    std::string m_name;
    /**
     * @brief Guild icon hash
     */
    std::string m_iconHash;
    /**
     * @brief Guild splash hash
     */
    std::string m_splashHash;
    /**
     * @brief whether user is owner or not
     */
    bool m_owner; //unneeded atm.
    /**
     * @brief Id of guild owner
     */
    Snowflake m_ownerId;
    /**
     * @brief Total permission for the user in the guild
     */
    int m_permissions;
    /**
     * @brief Region id for the guild
     */
    std::string m_region;
    /**
     * @brief Id of afk channel
     */
    Snowflake m_afkChannelId;
    /**
     * @brief Afk timeout in seconds
     */
    int m_afkTimeout;
    /**
     * @brief Guild embeddable or not
     */
    bool m_embedEnabled;
    /**
     * @brief Channel id that the widget will generate an invite to if not null
     */
    Snowflake m_embedChannelId;
    /**
     * @brief Verification level required for the guild
     * 
     */
    int m_verificationLevel;
    /**
     * @brief Default message notifications level
     */
    int m_defaultMessageNotifications;
    /**
     * @brief Explicit content filter level
     */
    int m_explicitContentFilter;

    //roles

    //emojis
    /**
     * @brief Vector containing all enabled guild features
     */
    std::vector<std::string> m_features;
    /**
     * @brief Required MFA level for the guild
     * https://discordapp.com/developers/docs/resources/guild#guild-object-mfa-level
     */
    int m_mfaLevel;
    /**
     * @brief 
     * Application id for guild creator, if its a bot-created guild
     */
    Snowflake m_applicationId;
    /**
     * @brief Whether or not the server widget is enabled
     */
    bool m_widgetEnabled;
    /**
     * @brief The channel id for the server widget
     */
    Snowflake m_widgetChannelId;
    /**
     * @brief The id of the channel to which system messages are sent
     */
    Snowflake m_systemChannelId;

    //Timestamp m_joinedAt
    /**
     * @brief Whether this is considered a large guild
     */
    bool m_large;
    /**
     * @brief Whether this guild is unavailable or not
     */
    bool m_unavailable;
    /**
     * @brief Total number of members in this guild
     */
    int m_memberCount;

    //voice_states? *	array of partial voice state objects	(without the guild_id key)

    //members

    //channels

    //presences
    /**
     * @brief The maximum amount of presences for the guild.
     * Default, currently 5000, is in effect when null is returned
     */
    int m_maxPresences; //default:5000
    /**
     * @brief The maximum amount of members for the guild
     */
    int m_maxMembers;
    /**
     * @brief The vanity url code for the guild
     */
    std::string m_vanityUrlCode;
    /**
     * @brief The description for the guild 
     */
    std::string m_description;
    /**
     * @brief Banner hash of the guild
     */
    std::string m_banner;
};
} // namespace dppcord

#endif