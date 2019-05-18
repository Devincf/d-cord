/**
 * @file GuildUser.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDUSER_HPP
#define GUILDUSER_HPP

#include "User.hpp"

/*


user	user object	the user this guild member represents
nick?	string	this users guild nickname (if one is set)
roles	array of snowflakes	array of role object ids
joined_at	ISO8601 timestamp	when the user joined the guild
deaf	boolean	whether the user is deafened in voice channels
mute	boolean	whether the user is muted in voice channels */

namespace dppcord
{
class GuildUser : public User
{
public:
private:
    /**
     * @brief The users guild nickname if one is set
     */
    std::string m_nickname;

    //roles

    //Timestamp joined_at
    /**
     * @brief Whether the user is deafened in voice channels or not
     */
    bool m_deaf;
    /**
     * @brief Whether the user is muted in voice channels or not
     */
    bool m_mute;
};
} // namespace dppcord

#endif