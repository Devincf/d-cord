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

const bool UsersHandler::addUser(User *pUser)
{
    return addUser(pUser->getId(), std::shared_ptr<User>(pUser));
}

const bool UsersHandler::addUser(const Snowflake &id, const std::shared_ptr<User>& pUser)
{
    auto res = m_userMap.insert({id, pUser});
    if (!res.second)
    {
        //already existed
        return false;
    }
    return true;
}
std::shared_ptr<User> UsersHandler::findUser(const Snowflake &id) const
{
    auto it = m_userMap.find(id);
    if (it == m_userMap.end())
    {
        return nullptr;
    }
    return it->second;
}
} // namespace dppcord