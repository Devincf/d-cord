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
UsersHandler();
~UsersHandler();
bool addUser(User* pUser);
bool addUser(Snowflake id, std::shared_ptr<User> pUser);
std::shared_ptr<User> findUser(Snowflake id);
private:
std::map<Snowflake,std::shared_ptr<User>> m_userMap;
};
} // namespace dppcord

#endif