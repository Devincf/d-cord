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

#include "dppcord/util/Timestamp.hpp"

namespace dppcord
{
/**
 * @brief TODO: uhh somehow make user a ptr in order to use globalusers
 */
class Guild;
class Role;
class GuildUser : public User
{
public:
    /**
     * @brief Construct a new Guild User object 
     * @param guserjson 
     */
    GuildUser(Guild* pGuild,const nlohmann::json &guserjson);
    GuildUser(Guild* pGuild, User* pUser,const nlohmann::json &guserjson);
    GuildUser(const GuildUser&) = default;

    /**
     * @brief Destroy the Guild User object
     */
    ~GuildUser();
private:
    /**
     * @brief Construct a new Guild User object
     */
    GuildUser();
    /**
     * @brief The users guild nickname if one is set
     */
    std::string m_nickname;
    /**
     * @brief Vector containing pointers to all of the roles the user currently has
     */
    std::vector<Role*> m_roles;
    /**
     * @brief Timestamp of when the user joined the guild
     */
    util::Timestamp m_joinedAt;
    /**
     * @brief Whether the user is deafened in voice channels or not
     */
    bool m_deaf;
    /**
     * @brief Whether the user is muted in voice channels or not
     */
    bool m_mute;
    /**
     * @brief The guild this guild user belongs to
     */
    Guild* m_guild;
};
} // namespace dppcord

#endif