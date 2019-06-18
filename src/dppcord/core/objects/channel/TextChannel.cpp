/**
 * @file TextChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-17 11:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/TextChannel.hpp"
//#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/rest/DiscordEndpoint.hpp"

namespace dppcord
{
TextChannel::TextChannel() {}
TextChannel::~TextChannel() {}
TextChannel::TextChannel(const nlohmann::json &channeldata) //: BaseChannel(channeldata)
{
}

BaseMessage &TextChannel::addMessage(BaseMessage *msg)
{
    m_messages.insert({msg->getId(), std::unique_ptr<BaseMessage>(msg)});
    m_lastMessage = msg;
    return *msg;
}
BaseMessage &TextChannel::getMessage(const Snowflake &id)
{
    auto ptr = m_messages.find(id);
    if (ptr == m_messages.end())
        throw std::runtime_error("Message with id " + std::to_string(id) + " not found");
    if (!ptr->second)
        throw std::runtime_error("Message is nullptr");
    std::cout << ptr->second->str();
    return *ptr->second;
}

BaseMessage &TextChannel::sendMessage(const std::string &msg)
{
    auto newmsgjson = DiscordEndpoint::sendMessage(m_id, msg);
    BaseMessage *m = new BaseMessage(*this, newmsgjson);
    addMessage(m);
    return *m;
}

bool TextChannel::hasMessage(const Snowflake &id)
{
    return m_messages.find(id) != m_messages.end();
}

BaseMessage &TextChannel::sendMessageExtended(const nlohmann::json &json)
{
    auto newmsgjson = DiscordEndpoint::sendMessageExtended(m_id, json);
    BaseMessage *m = new BaseMessage(*this, newmsgjson);
    addMessage(m);
    return *m;
}
bool TextChannel::removeMessage(const Snowflake &id)
{
    //DiscordEndpoint::deleteMessage(std::to_string(m_id), std::to_string(id));
    return m_messages.erase(id) != 0;
}

const BaseMessage &TextChannel::getLastMessage() const { return *m_lastMessage; }
} // namespace dppcord