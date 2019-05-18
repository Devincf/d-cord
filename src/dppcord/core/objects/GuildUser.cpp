/**
 * @file GuildUser.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/GuildUser.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    GuildUser::GuildUser(){}
    GuildUser::~GuildUser(){}
    GuildUser::GuildUser(const nlohmann::json& guserjson): User(guserjson["user"])
    {
        m_nickname = tryGetJson<std::string>("nick",guserjson);
        //roles
        //joined_at
        m_deaf = tryGetJson<bool>("deaf",guserjson);
        m_mute = tryGetJson<bool>("mute",guserjson);
    }
}