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

#include "dppcord/core/objects/user/GuildUser.hpp"
#include "dppcord/core/objects/emoji/Emoji.hpp"
#include "dppcord/core/objects/Role.hpp"
#include "dppcord/core/objects/IIdentifiableObject.hpp"
#include "dppcord/core/objects/INamedObject.hpp"

namespace dppcord
{
class UsersHandler;
class BaseChannel;
class BaseMessage;
class Guild : public IIdentifiableObject, public INamedObject
{
public:
    /**
     * @brief Construct a new Guild object from a given json object
     * @param guildjson the json object to construct the guild from
     * @param pUserHandler pointer to Userhandler if you want to use global userlists
     */
    Guild(const nlohmann::json &guildjson, UsersHandler &pUserHandler);
    /**
     * @brief Destroy the Guild object
     */
    ~Guild();
    /**
     * @brief Returns a pointer to a role object with a given id
     * @param id of the role
     * @return std::shared_ptr<Role> 
     */
    std::shared_ptr<Role> getRole(const Snowflake &id);
    /**
     * @brief Returns a pointer to a user object with a given id inside the guild
     * @param id of the user
     * @return std::shared_ptr<User> , nullptr if it doesnt exist
     */
    std::shared_ptr<User> getUserFromId(const Snowflake &id);
    /**
     * @brief Returns a pointer to a channel object with a given id inside the guild
     * @param id of the channel
     * @return std::shared_ptr<Channel> , nullptr if it doesnt exist
     */
    std::shared_ptr<BaseChannel> getChannel(const Snowflake &id);
    /**
     * @brief Constructs and returns a new channel object
     * @param channeldata the channel information as a json object
     * @return std::shared_ptr<BaseChannel> the pointer that belongs to the new channel
     */
    std::shared_ptr<BaseChannel> addChannel(const nlohmann::json &channeldata);
    /**
     * @brief Adds a Message into the Message map
     * @param msg 
     */
    void addMessage(const std::shared_ptr<BaseMessage> &msg);
    /**
     * @brief Returns the pointer to the message with id if exists, nullptr otherwise
     * @param id of the message to get
     * @return std::shared_ptr<BaseMessage> 
     */
    std::shared_ptr<BaseMessage> getMessage(const Snowflake &id);
    /**
     * @brief Removes a Message 
     * @param id 
     */
    void removeMessage(const Snowflake& id);

private:
    /**
     * @brief Construct a new Guild object
     */
    Guild();
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
     * @brief Pointer to the owner user object
     */
    std::shared_ptr<User> m_ownerPtr;
    /**
     * @brief Total permission for the user in the guild
     */
    int m_permissions;
    /**
     * @brief Region id for the guild
     */
    std::string m_region;
    /**
     * @brief Pointer to the afk channel
     */
    BaseChannel *m_afkChannel;
    /**
     * @brief Afk timeout in seconds
     */
    int m_afkTimeout;
    /**
     * @brief Guild embeddable or not
     */
    bool m_embedEnabled;
    /**
     * @brief  Pointer to the channel that the widget will generate an invite to if not null
     */
    BaseChannel *m_embedChannel;
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
    /**
     * @brief Vector ccontaining all guild specific roles
     */
    std::map<Snowflake, std::shared_ptr<Role>> m_roles;
    /**
     * @brief Vector containing all guild specific emojis
     */
    std::vector<Emoji> m_emojis;
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
     * @brief  Pointer to the channel for the server widget
     */
    BaseChannel *m_widgetChannel;
    /**
     * @brief  Pointer to the of the channel to which system messages are sent
     */
    BaseChannel *m_systemChannel;

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
     * TODO: probably unneeded and will be replaced with m_members.size()
     */
    int m_memberCount;

    //voice_states? *	array of partial voice state objects	(without the guild_id key)

    /**
     * @brief Vector containing all guild members
     */
    std::vector<std::shared_ptr<User>> m_members;
    /**
     * @brief Vector containing all guild channels
     * TODO: switch to Channel* after Channel has been split into different objects
     */
    std::vector<std::shared_ptr<BaseChannel>> m_channels;
    /**
     * @brief Map containing all Messages sorted by their id
     */
    std::map<Snowflake, std::shared_ptr<BaseMessage>> m_messages;

    //presences
    /**
     * @brief The maximum amount of presences for the guild.
     * Default, currently 5000, is in effect when null is returned
     */
    int m_maxPresences;
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