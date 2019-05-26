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
class BaseChannel : public IIdentifiableObject // Todo: split text/voice/dm channels
{
public:
    /**
     * @brief Construct a new Channel object with given json data
     * @param json data to construct the Channel object from
     */
    BaseChannel(const nlohmann::json& channeljson);
    /**
     * @brief Destroy the Channel object
     */
    virtual ~BaseChannel();
protected:
    /**
     * @brief Construct a new Channel object
     */
    BaseChannel();
    /**
     * @brief Type of the channel 
     * Todo: replace with enum maybe or defines
     */
    int m_type;

    //permission_overwrites?	array of overwrite objects	explicit permission overwrites for members and roles
    /**
     * @brief The bitrate (in bits) of the channel , if its a voice channel
     */
    int m_bitrate;
    /**
     * @brief The user limit of this channel, if its a voice channel
     */
    int m_userLimit;

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

    //Timestamp m_lastPinTimestamp;
};
} // namespace dppcord

#endif