/**
 * @file BaseMessage.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-25 08:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/GuildChannel.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
BaseMessage::BaseMessage() {}

BaseMessage::BaseMessage(BaseChannel* pChannel, const nlohmann::json &msgjson, User* author)
{
    m_channel = pChannel;
    GuildChannel& channel = *(dynamic_cast<GuildChannel*>(pChannel));
    m_id = tryGetSnowflake("id", msgjson);
    //std::cout << msgjson.dump(1) << '\n';
    Snowflake test = tryGetSnowflake("id", msgjson["author"]);
    if(author == nullptr)
        m_author = &channel.getGuild().getUserFromId(test);
    else
        m_author = author;
    
    m_content = tryGetJson<std::string>("content", msgjson);
    m_timestamp = util::Timestamp(tryGetJson<std::string>("timestamp", msgjson));
    m_tts = tryGetJson<bool>("tts", msgjson);
    m_mentionEveryone = tryGetJson<bool>("mention_everyone", msgjson);
    m_nonce = tryGetSnowflake("nonce", msgjson);
    m_pinned = tryGetJson<bool>("pinned",msgjson);
    m_webhookId = tryGetSnowflake("webhook_id",msgjson);
    m_type = tryGetJson<int>("type",msgjson);
}

BaseMessage::~BaseMessage() 
{
}

bool BaseMessage::remove()
{
    return DiscordEndpoint::deleteMessage(std::to_string(m_channel->getId()), std::to_string(m_id));
    //std::dynamic_pointer_cast<GuildChannel>(m_channel)->getGuild()->removeMessage(m_id);
}

bool BaseMessage::react(const std::string& emoji)
{
    //emoji takes the form of name:id for custom guild emoji,
    return DiscordEndpoint::createReaction(std::to_string(m_channel->getId()), std::to_string(m_id), emoji);
}

std::string BaseMessage::str() const
{
    std::stringstream ss;
    ss << m_author->getName() << " at " << m_timestamp.getISOTime() << " in channel " << dynamic_cast<GuildChannel&>(*m_channel).getName() << " : " << m_content;
    return ss.str();
}

User& BaseMessage::author() const { return *m_author; }
const std::string& BaseMessage::content() const { return m_content; }
BaseChannel& BaseMessage::channel()const {return *m_channel;}
} // namespace dppcord