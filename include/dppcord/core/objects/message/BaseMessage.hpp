/**
 * @file BaseMessage.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-25 08:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BASEMESSAGE_HPP
#define BASEMESSAGE_HPP
#include <memory>

#include "nlohmann/json.hpp"


#include "dppcord/core/objects/IIdentifiableObject.hpp"

#include "dppcord/util/Timestamp.hpp"

namespace dppcord
{
class BaseChannel;
class User;
class BaseMessage: public IIdentifiableObject
{
public:
    /**
     * @brief Destroy the Base Message object
     */
    virtual ~BaseMessage();
    /**
     * @brief Construct a new Base Message object
     * @param pChannel Pointer to the channel this message got posted in.
     * @param msgjson json data of the message
     */
    BaseMessage(std::shared_ptr<BaseChannel> pChannel, const nlohmann::json& msgjson);
    /**
     * @brief Returns the content of the message
     * @return std::string 
     */
    std::string content();
    /**
     * @brief Returns the channel the message has been posted in
     * @return std::shared_ptr<BaseChannel> 
     */
    std::shared_ptr<BaseChannel> channel();

protected:
    /**
     * @brief Construct a new Base Message object
     */
    BaseMessage();

private:
    /**
     * @brief Pointer to the Channel this message was posted in
     */
    std::shared_ptr<BaseChannel> m_channel;
    /**
     * @brief Pointer to the User that created this message
     */
    std::shared_ptr<User> m_author;
    /**
     * @brief Content of the Message
     */
    std::string m_content;
    /**
     * @brief First posted timestamp
     */
    util::Timestamp m_timestamp;
    /**
     * @brief Last edited timestamp
     */
    util::Timestamp m_editedTimestamp;
    /**
     * @brief Whether this was a tts message or not
     */
    bool m_tts;
    /**
     * @brief Whether \@everyone got mentioned or not
     */
    bool m_mentionEveryone;

    //mentions	array of user objects, with an additional partial member field	users specifically mentioned in the message
    //std::vector<std::shared_ptr<User>> m_mentions;

    //mention_roles	array of role object ids	roles specifically mentioned in this message
    //std::vector<std::shared_ptr<Role>> m_roleMentions;

    /* TODO: implement
attachments	array of attachment objects	any attached files
embeds	array of embed objects	any embedded content
reactions?	array of reaction objects	reactions to the message
*/
    /**
     * @brief TODO: understand wtf this means
     */
    Snowflake m_nonce;
    /**
     * @brief Whether this message is pinned or not
     */
    bool m_pinned;
    /**
     * @brief id of the webhook that was used to post this
     * null if non existant
     */
    Snowflake m_webhookId;
    /**
     * @brief Message Type
     * TODO: replace with MessageType enum
     */
    int m_type;

/**
 * TODO: implement
activity?	message activity object	sent with Rich Presence-related chat embeds
application?	message application object	sent with Rich Presence-related chat embeds
 */


};
} // namespace dppcord
#endif