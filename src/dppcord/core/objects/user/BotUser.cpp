/**
 * @file BotUser.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-04 05:59
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/user/BotUser.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    BotUser::BotUser(const nlohmann::json& botdata): User(botdata["user"])
    {
        m_sessionId = tryGetJson<std::string>("session_id", botdata);
    }

    const std::string& BotUser::getSessionId()const { return m_sessionId; }
}