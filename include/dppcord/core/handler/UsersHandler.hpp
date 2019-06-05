/**
 * @file UsersHandler.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 08:19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef USERSHANDLER_HPP
#define USERSHANDLER_HPP

#include "dppcord/core/objects/user/User.hpp"

namespace dppcord
{
class UsersHandler
{
public:
    /**
     * @brief Construct a new Users Handler object
     */
    UsersHandler();
    /**
     * @brief Destroy the Users Handler object
     */
    ~UsersHandler();
    /**
     * @brief Adds a user into the global User map
     * @param pointer to the User object that should be inserted.
     * @return Whether the User didnt exist in the map before
     */
    const bool addUser(User * const pUser);
    /**
     * @brief Checks whether a User id exists in the global user map
     * @param id to look for
     * @return std::shared_ptr<User> of the user. nullptr if no user was found
     */
    User& findUser(const Snowflake& id) const;
    /**
     * @brief Checks whether a User exists or not
     * @param id of the user
     * @return bool true if user exists
     */
    const bool userExists(const Snowflake& id) const;
    /**
     * @brief Returns the total amount of global Users
     * @return const int 
     */
    const int globalAmount() const;

private:
    /**
     * @brief Map containing all global users 
     */
    std::map<Snowflake, std::unique_ptr<User>> m_userMap;
};
} // namespace dppcord

#endif