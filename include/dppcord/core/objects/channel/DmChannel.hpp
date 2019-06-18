/**
 * @file DmChannel.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 10:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DMCHANNEL_HPP
#define DMCHANNEL_HPP

#include "TextChannel.hpp"

namespace dppcord
{
class DmChannel : public TextChannel
{
public:
    /**
     * @brief Construct a new Dm Channel object
     * @param channeljson 
     */
    DmChannel(const nlohmann::json &channeljson);
    /**
     * @brief Destroy the Dm Channel object
     */
    ~DmChannel();
    DmChannel(const DmChannel&) = default;

protected:
private:
    //TODO: recipients
};
} // namespace dppcord

#endif