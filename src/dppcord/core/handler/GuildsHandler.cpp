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
const bool GuildsHandler::addGuild(Guild* const rGuild)
{
    auto res = m_guildMap.insert({rGuild->getId(), std::unique_ptr<Guild>(rGuild)});
    if(!res.second)
    {
        //already existed.
        return false;
    }
    return true;
}

const int GuildsHandler::amount() const
{
    return m_guildMap.size();
}

Guild& GuildsHandler::getGuild(const Snowflake& id) const
{
    auto ptr = m_guildMap.find(id);

    if(ptr == m_guildMap.end()) throw std::runtime_error("Guild not found"); 
    if(!ptr->second) throw std::runtime_error("Guild is nullptr");

    return *ptr->second.get();
}
} // namespace dppcord