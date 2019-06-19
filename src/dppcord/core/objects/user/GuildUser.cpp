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

#include "dppcord/core/objects/user/GuildUser.hpp"

#include "dppcord/core/objects/guild/Guild.hpp"

#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
GuildUser::GuildUser() {}
GuildUser::~GuildUser() {}
GuildUser::GuildUser(Guild* pGuild, const nlohmann::json &guserjson):User(guserjson["user"])
{
    m_guild = pGuild;
    m_nickname = tryGetJson<std::string>("nick", guserjson);
    for(auto it = guserjson["roles"].begin();it!= guserjson["roles"].end();it++)
    {
        m_roles.push_back(&m_guild->getRole(*it));
    }
    m_joinedAt = util::Timestamp(tryGetJson<std::string>("joined_at", guserjson));
    m_deaf = tryGetJson<bool>("deaf", guserjson);
    m_mute = tryGetJson<bool>("mute", guserjson);
}
GuildUser::GuildUser(Guild* pGuild, User* pUser,const nlohmann::json &guserjson):User(*pUser)
{
    GuildUser(pGuild,guserjson);
}
} // namespace dppcord