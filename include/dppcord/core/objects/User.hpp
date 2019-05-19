/**
 * @file User.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef USER_HPP
#define USER_HPP

#include "Snowflake.hpp"

namespace dppcord
{
class User
{
public:
User(const nlohmann::json& userjson);
virtual ~User();
protected:
User();
private:
    /**
     * @brief User's id
     */
    Snowflake m_id;
    /**
     * @brief The user's username. not unique across the platform 
     */
    std::string m_username;
    /**
     * @brief The user's 4-digit discord-tag
     */
    std::string m_discriminator;
    /**
     * @brief The user's avatar hash
     */
    std::string m_avatarHash;
    /**
     * @brief Whether the user is a bot or not
     */
    bool m_bot;
    /**
     * @brief Whether the user has two factor enabled or not
     */
    bool m_mfaEnabled;
    /**
     * @brief the user's chosen language option
     */
    std::string m_locale;
    /**
     * @brief Whether the email on this account has been verified
     */
    bool m_verified;
    /**
     * @brief The user's email
     */
    std::string m_email;
    /**
     * @brief The flags on a user's account
     */
    int m_flags;
    /**
     * @brief The type of nitro subscription on a user's account
     */
    int m_premiumType;
};
} // namespace dppcord

#endif