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
#include "dppcord/core/objects/channel/Channel.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
BaseMessage::BaseMessage() {}
BaseMessage::BaseMessage(const nlohmann::json& msgjson):BaseMessage(nullptr, msgjson) {}

BaseMessage::BaseMessage(std::shared_ptr<Channel> pChannel, const nlohmann::json &msgjson):m_channel(pChannel)
{
    m_id = tryGetSnowflake("id", msgjson);
    //std::cout << msgjson.dump(1) << '\n';
    Snowflake test = tryGetSnowflake("id", msgjson["author"]);
    m_author = pChannel->getGuild()->getUserFromId(test);
    m_content = tryGetJson<std::string>("content", msgjson);
    m_timestamp = util::Timestamp(tryGetJson<std::string>("timestamp", msgjson));
    m_tts = tryGetJson<bool>("tts", msgjson);
    m_mentionEveryone = tryGetJson<bool>("mention_everyone", msgjson);
    m_nonce = tryGetSnowflake("nonce", msgjson);
    m_pinned = tryGetJson<bool>("pinned",msgjson);
    m_webhookId = tryGetSnowflake("webhook_id",msgjson);
    m_type = tryGetJson<int>("type",msgjson);

    std::cout << "new message from: " << m_author->getName() << " at " << m_timestamp.getISOTime() << " in channel: " << pChannel->getName() << '\n';
}

BaseMessage::~BaseMessage() {}
} // namespace dppcord