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

#include "../LambdaCommand.hpp"
#include "../WrappedCommand.hpp"

namespace dppcord
{
class CommandMap
{
public:
    static void addCommand(const std::string &cmdStr, Command *pCmd);
    template <typename T>
    static void addCommand(const std::string &cmdStr, T fn)
    {
        addCommand(cmdStr, std::function(fn));
    }

    template <typename... Args>
    static void addCommand(const std::string &cmdStr, const std::function<void(Args...)> &fn)
    {
    std::cout << m_commandMap.size();
        auto it = m_commandMap.find(cmdStr);
        if (it == m_commandMap.end())
        {
            std::cout << "adding command " << cmdStr << '\n';
            m_commandMap.insert({cmdStr,{std::make_shared<LambdaCommand<Args...>>(fn)}});
            std::cout << m_commandMap[cmdStr].at(0)->getArgumentCount();
        }
        else
        {
            it->second.push_back(std::make_shared<LambdaCommand<Args...>>(fn));
        }
    std::cout << m_commandMap.size();
    }

    static std::vector<std::shared_ptr<Command>> getCommand(const std::string &cmdStr);

private:
    static std::map<std::string, std::vector<std::shared_ptr<Command>>> m_commandMap;
};
} // namespace dppcord
#endif