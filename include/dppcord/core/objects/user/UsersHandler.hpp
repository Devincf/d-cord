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
    bool addUser(User *pUser);
    /**
     * @brief Adds a user into the global User map
     * @param user id
     * @param shared_ptr to the user 
     * @return Whether the User didnt exist in the map before
     */
    bool addUser(Snowflake id, std::shared_ptr<User> pUser);
    /**
     * @brief Checks whether a User id exists in the global user map
     * @param id to look for
     * @return std::shared_ptr<User> of the user. nullptr if no user was found
     */
    std::shared_ptr<User> findUser(Snowflake id);

private:
    /**
     * @brief Map containing all global users 
     */
    std::map<Snowflake, std::shared_ptr<User>> m_userMap;
};
} // namespace dppcord

#endif