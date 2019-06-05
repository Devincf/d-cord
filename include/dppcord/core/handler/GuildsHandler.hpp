/**
 * @file GuildsHandler.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GUILDSHANDLER_HPP
#define GUILDSHANDLER_HPP

#include <vector>

#include "dppcord/core/objects/guild/Guild.hpp"

namespace dppcord
{
class GuildsHandler
{
public:
    /**
     * @brief Construct a new Guilds Handler object
     */
    GuildsHandler();
    /**
     * @brief Destroy the Guilds Handler object
     */
    ~GuildsHandler();
    /**
     * @brief Adds a guild into map through a rval reference.
     * @param rGuild Guild to be added
     * @return whether the guild didnt exist in the map before or not
     */
    const bool addGuild(Guild * const rGuild);

    /**
     * @brief Returns a pointer to the guild with a given id
     * @param id of the guild
     * @return Guild* , nullptr if no guild was found
     */
    Guild& getGuild(const Snowflake& id) const;
    /**
     * @brief Returns the Amount of Guilds
     * @return const int 
     */
    const int amount() const;

private:
    /**
     * @brief Map containing every Guild the bot is in
     */
    std::map<Snowflake, std::unique_ptr<Guild>> m_guildMap;
};
} // namespace dppcord

#endif