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
    virtual ~BaseMessage();

    BaseMessage(const nlohmann::json& msgjson);
    BaseMessage(std::shared_ptr<BaseChannel> pChannel, const nlohmann::json& msgjson);

protected:
    BaseMessage();

private:

    std::shared_ptr<BaseChannel> m_channel;

    std::shared_ptr<User> m_author;

    std::string m_content;

    util::Timestamp m_timestamp;

    util::Timestamp m_editedTimestamp;

    bool m_tts;

    bool m_mentionEveryone;

    //mentions	array of user objects, with an additional partial member field	users specifically mentioned in the message
    //std::vector<std::shared_ptr<User>> m_mentions;

    //mention_roles	array of role object ids	roles specifically mentioned in this message
    //std::vector<std::shared_ptr<Role>> m_roleMentions;

    /* Todo: implement
attachments	array of attachment objects	any attached files
embeds	array of embed objects	any embedded content
reactions?	array of reaction objects	reactions to the message
*/
    Snowflake m_nonce;

    bool m_pinned;

    Snowflake m_webhookId;

    int m_type;

/**
 * Todo: implement
activity?	message activity object	sent with Rich Presence-related chat embeds
application?	message application object	sent with Rich Presence-related chat embeds
 */


};
} // namespace dppcord
#endif