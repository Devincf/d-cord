/**
 * @file GuildsHandler.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 08:00
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/guild/GuildsHandler.hpp"

namespace dppcord
{
GuildsHandler::GuildsHandler() {}
GuildsHandler::~GuildsHandler() {}
bool GuildsHandler::addGuild(Guild &&rGuild)
{
    auto res = m_guildMap.insert({rGuild.getId(), rGuild});
    if(!res.second)
    {
        //already existed.
        return false;
    }
    return true;
}
} // namespace dppcord