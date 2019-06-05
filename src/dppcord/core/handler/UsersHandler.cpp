/**
 * @file UsersHandler.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 08:19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/handler/UsersHandler.hpp"

namespace dppcord
{
UsersHandler::UsersHandler() {}
UsersHandler::~UsersHandler() {}

const bool UsersHandler::addUser(User * const pUser)
{
    auto res = m_userMap.insert({pUser->getId(), std::unique_ptr<User>(pUser)});
    if (!res.second)
    {
        //already existed
        return false;
    }
    return true;
}

const int UsersHandler::globalAmount() const
{
    return m_userMap.size();
}

const bool UsersHandler::userExists(const Snowflake& id) const
{
    return m_userMap.find(id) != m_userMap.end();
}

User& UsersHandler::findUser(const Snowflake &id) const
{
    auto it = m_userMap.find(id);
    if (it == m_userMap.end()) throw std::runtime_error("User with id " + std::to_string(id) + " not found");
    if (!it->second) throw std::runtime_error("User is nullptr");
    return *it->second;
}
} // namespace dppcord