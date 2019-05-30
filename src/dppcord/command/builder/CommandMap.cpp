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

std::vector<std::shared_ptr<Command>> CommandMap::getCommand(const std::string &cmdStr)
{
    auto it = m_commandMap.find(cmdStr);
    if (it == m_commandMap.end())
    {
        std::cout << "no cmd found\n";
        return {};
    }
    return it->second;
}
std::map<std::string,std::vector<std::shared_ptr<Command>>> CommandMap::m_commandMap = {};
}