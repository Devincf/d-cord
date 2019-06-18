/**
 * @file BotUser.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-04 05:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOTUSER_HPP
#define BOTUSER_HPP

#include "User.hpp"

namespace dppcord
{
class BotUser : public User
{
public:
    BotUser(const nlohmann::json& botdata);
    ~BotUser() = default;
    BotUser(const BotUser&) = default;
    BotUser() = default;

    const std::string& getSessionId() const;
private:

    std::string m_sessionId;


};
} // namespace dppcord

#endif