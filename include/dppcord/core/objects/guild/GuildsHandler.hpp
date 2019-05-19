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

#include "Guild.hpp"

namespace dppcord
{
    class GuildsHandler
    {
        public:
        GuildsHandler();
        ~GuildsHandler();
        bool addGuild(Guild&& rGuild);
        private:
        std::map<Snowflake, Guild> m_guildMap;
    };
}

#endif