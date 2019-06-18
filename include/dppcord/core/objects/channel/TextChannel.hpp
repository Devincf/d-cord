/**
 * @file TextChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-17 11:25
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TEXTCHANNEL_HPP
#define TEXTCHANNEL_HPP

#include "dppcord/core/objects/channel/BaseChannel.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"


namespace dppcord
{
//class BaseMessage;
class TextChannel: virtual public BaseChannel
{
public:
    TextChannel();
    virtual ~TextChannel();
    TextChannel(const nlohmann::json& channeldata);

    BaseMessage &addMessage(BaseMessage* msg);

    BaseMessage& getMessage(const Snowflake& id);

    bool removeMessage(const Snowflake& id);

    bool hasMessage(const Snowflake& id);


    /**
     * @brief Sends a message in this channel
     * @param msg 
     */
    BaseMessage& sendMessage(const std::string& msg);
    /**
     * @brief Sends a message in this channel from a json object
     * @param json 
     * @return std::shared_ptr<BaseMessage> 
     */
    BaseMessage& sendMessageExtended(const nlohmann::json& json);
    
    const BaseMessage& getLastMessage() const;
private:
    std::map<Snowflake,std::unique_ptr<BaseMessage>> m_messages;
    /**
     * @brief Pointer to the last Message object
     */
    const BaseMessage *m_lastMessage;
};
} // namespace dppcord
#endif