/**
 * @file CommandMap.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/builder/CommandMap.hpp"

#include "dppcord/command/LambdaCommand.hpp"
#include "dppcord/command/WrappedCommand.hpp"

namespace dppcord
{
void CommandMap::addCommand(const std::string &cmdStr, Command *pCmd)
{
    auto it = m_commandMap.find(cmdStr);
    if (it == m_commandMap.end())
    {
        m_commandMap.insert({cmdStr, std::vector<std::shared_ptr<Command>>{std::shared_ptr<Command>(pCmd)}});
    }
    else
    {
        it->second.push_back(std::shared_ptr<Command>(pCmd));
    }
}


/*void CommandMap::addCommand(const std::string &cmdStr, void (*fn)(DiscordClient *, const ArgumentList &))
{
    addCommand(cmdStr, std::function(fn));
}*/

void CommandMap::addCommand(const std::string &cmdStr, const callback &fn)
{
    auto it = m_commandMap.find(cmdStr);
    if (it == m_commandMap.end())
    {
        //std::cout << "adding command " << cmdStr << '\n';
        m_commandMap.insert({cmdStr, {std::make_shared<LambdaCommand>(fn)}});
    }
    else
    {
        it->second.push_back(std::make_shared<LambdaCommand>(fn));
    }
}

std::vector<std::shared_ptr<Command>> CommandMap::getCommand(const std::string &cmdStr)
{
    auto it = m_commandMap.find(cmdStr);
    if (it == m_commandMap.end())
    {
        //std::cout << "no cmd found\n";
        return {};
    }
    return it->second;
}

std::map<std::string, std::vector<std::shared_ptr<Command>>> CommandMap::m_commandMap = {};
} // namespace dppcord