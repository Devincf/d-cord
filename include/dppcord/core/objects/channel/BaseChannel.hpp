/**
 * @file BaseChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:37
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BASECHANNEL_HPP
#define BASECHANNEL_HPP

#include "dppcord/core/objects/IIdentifiableObject.hpp"
#include "dppcord/core/objects/INamedObject.hpp"
namespace dppcord
{
class Guild;
class User;
class BaseMessage;
class BaseChannel : public IIdentifiableObject // TODO: split text/voice/dm channels
{
public:
    /**
     * @brief Construct a new Channel object with given json data
     * @param json data to construct the Channel object from
     */
    BaseChannel(const rapidjson::Document& channeljson);
    /**
     * @brief Destroy the Channel object
     */
    virtual ~BaseChannel();
    /**
     * @brief Sends a message in this channel
     * @param msg 
     */
    virtual std::shared_ptr<BaseMessage> sendMessage(const std::string& msg);
protected:
    /**
     * @brief Construct a new Channel object
     */
    BaseChannel();
    /**
     * @brief Type of the channel 
     * TODO: replace with enum maybe or defines
     */
    int m_type;

    //permission_overwrites?	array of overwrite objects	explicit permission overwrites for members and roles

    //recipients?	array of user objects	the recipients of the DM
    /**
     * @brief Icon hash
     */
    std::string m_iconHash;
    /**
     * @brief Owner of the DM Channel
     * TODO: replace with User*
     */
    //std::shared_ptr<User> m_owner;
    /**
     * @brief Application id of owner if group dm is bot created
     * TODO: replace with User*
     */
    //std::shared_ptr<User> m_application; 

    //Timestamp m_lastPinTimestamp;
};
} // namespace dppcord

#endif