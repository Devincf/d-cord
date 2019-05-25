/**
 * @file Channel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:37
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "../Snowflake.hpp"
namespace dppcord
{
class Guild;
class User;
class Channel // Todo: split text/voice/dm channels
{
public:
    /**
     * @brief Construct a new Channel object with given json data
     * @param json data to construct the Channel object from
     */
    Channel(Guild* pGuild, const nlohmann::json& channeljson);
    /**
     * @brief Destroy the Channel object
     */
    ~Channel();
    /**
     * @brief Returns the id of the channel
     * @return Snowflake 
     */
    Snowflake getId();
    /**
     * @brief Returns the name of the channel
     * @return std::string 
     */
    std::string getName();
private:
    /**
     * @brief Construct a new Channel object
     */
    Channel();
    /**
     * @brief The id of this channel
     */
    Snowflake m_id;
    /**
     * @brief Type of the channel 
     * Todo: replace with enum maybe or defines
     */
    int m_type;
    /**
     * @brief The Guild this channel belongs to
     * Todo: implement
     */
    //Guild *m_guild;
    /**
     * @brief Integer sorting position of this channel
     */
    int m_position;

    //permission_overwrites?	array of overwrite objects	explicit permission overwrites for members and roles
    /**
     * @brief The name of the channel(2-100 chars)
     */
    std::string m_name;
    /**
     * @brief The channel topic(0-1024 chars)
     */
    std::string m_topic;
    /**
     * @brief Whether this channel is nsfw
     */
    bool m_nsfw;
    /**
     * @brief Last message id
     * Todo: replace with Message* 
     */
    Snowflake m_lastMessageId;
    /**
     * @brief The bitrate (in bits) of the channel , if its a voice channel
     */
    int m_bitrate;
    /**
     * @brief The user limit of this channel, if its a voice channel
     */
    int m_userLimit;
    /**
     * @brief Amount of seconds a user has to wait before sendinc another message(0-21600); 
     * bots as well as users with the permission manage_messages or manage_channel, are unaffected
     */
    int m_rateLimitPerUser;

    //recipients?	array of user objects	the recipients of the DM
    /**
     * @brief Icon hash
     */
    std::string m_iconHash;
    /**
     * @brief Owner of the DM Channel
     * Todo: replace with User*
     */
    //std::shared_ptr<User> m_owner;
    /**
     * @brief Application id of owner if group dm is bot created
     * Todo: replace with User*
     */
    //std::shared_ptr<User> m_application; 
    /**
     * @brief Id of parent category for the channel
     * Todo: replace with Channel*
     */
    Snowflake m_parentId;
    /**
     * @brief Guild this channel belongs to
     * Todo: some changes when channels get split
     */
    Guild* m_guild;

    //Timestamp m_lastPinTimestamp;
};
} // namespace dppcord

#endif