/**
 * @file CommandMap.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 02:46
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMANDMAP_HPP
#define COMMANDMAP_HPP

#include <map>
#include <memory>
#include <functional>
#include <iostream>

#include "../Command.hpp"

namespace dppcord
{
class CommandMap
{
public:
    static void addCommand(const std::string &cmdStr, Command *pCmd);
    
    //static void addCommand(const std::string &cmdStr, void (*fn)(DiscordClient*, const ArgumentList&));

    static void addCommand(const std::string &cmdStr, const callback& fn);

    static std::vector<std::shared_ptr<Command>> getCommand(const std::string &cmdStr);

private:
    static std::map<std::string, std::vector<std::shared_ptr<Command>>> m_commandMap;
};
} // namespace dppcord
#endif