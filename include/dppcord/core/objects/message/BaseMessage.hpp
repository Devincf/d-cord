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
#include <functional>

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
     */
    BaseMessage();
    BaseMessage(const BaseMessage& rhs) = default;
    /**
     * @brief Construct a new Base Message object
     * @param pChannel Pointer to the channel this message got posted in.
     * @param msgjson json data of the message
     */
    BaseMessage(BaseChannel& pChannel, const nlohmann::json& msgjson);
    /**
     * @brief Returns the content of the message
     * @return std::string 
     */
    const std::string& content() const;
    /**
     * @brief Returns the channel the message has been posted in
     * @return std::shared_ptr<BaseChannel> 
     */
    BaseChannel& channel() const;
    /**
     * @brief Removes the message
     * @return std::string 
     */
    std::string remove();
    /**
     * @brief React to this message with a given emoji
     * @param emoji to be used for reaction
     * @return std::string 
     */
    std::string react(const std::string& emoji);

    void reactionListener(const nlohmann::json& json)
    {
        m_reactionListener(*this, json);
    }

    void reactionListener(const std::function<void(BaseMessage& msg, const nlohmann::json& )>& fn)
    {
        m_reactionListener = fn;
    }

protected:

private:
    /**
     * @brief Pointer to the Channel this message was posted in
     */
    BaseChannel* m_channel;
    /**
     * @brief Pointer to the User that created this message
     */
    User* m_author;
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


    std::function<void(BaseMessage& msg, const nlohmann::json&)> m_reactionListener;

/**
 * TODO: implement
activity?	message activity object	sent with Rich Presence-related chat embeds
application?	message application object	sent with Rich Presence-related chat embeds
 */


};
} // namespace dppcord
#endif