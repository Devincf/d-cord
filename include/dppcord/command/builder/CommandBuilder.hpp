/**
 * @file CommandBuilder.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 02:58
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMANDBUILDER_HPP
#define COMMANDBUILDER_HPP

#include "CommandMap.hpp"

namespace dppcord
{
class CommandBuilder
{
public:
    static bool tryBuildCommand(const std::string &cmdStr);

    static std::shared_ptr<Command> findFirstCandidate(const std::vector<std::shared_ptr<Command>> &cmds, int argSize);
};
} // namespace dppcord

#endif