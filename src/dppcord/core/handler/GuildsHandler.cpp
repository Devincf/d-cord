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

#include "dppcord/core/handler/GuildsHandler.hpp"

namespace dppcord
{
GuildsHandler::GuildsHandler() {}
GuildsHandler::~GuildsHandler() {}
const bool GuildsHandler::addGuild(Guild* rGuild)
{
    auto res = m_guildMap.insert({rGuild->getId(), std::shared_ptr<Guild>(rGuild)});
    if(!res.second)
    {
        //already existed.
        return false;
    }
    return true;
}
std::shared_ptr<Guild> GuildsHandler::getGuild(const Snowflake& id) const
{
    auto ptr = m_guildMap.find(id);
    if(ptr == m_guildMap.end())
    {
        return nullptr;
    }
    return ptr->second;
}
} // namespace dppcord