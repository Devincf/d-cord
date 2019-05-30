/**
 * @file CommandBuilder.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/command/builder/CommandMap.hpp"
#include "dppcord/command/parser/CommandParser.hpp"

namespace dppcord
{
bool CommandBuilder::tryBuildCommand(const std::string &cmdStr)
{
    std::cout << "parsing arguments";
    auto parsedCommand = CommandParser::parse(cmdStr);
    std::cout << "searching for command " << parsedCommand.name.name << "...\n";
    auto arguments = parsedCommand.arguments;

    auto commands = CommandMap::getCommand(parsedCommand.name.name);
    if (commands.size() == 0)
        return false; // Command doesnt exist.


    auto command = findFirstCandidate(commands, arguments.size());
    if(!command)
        std::cout << "No command with correct arguments found.\n";
    if(command != nullptr)
        std::cout << "calling internal_proc\n";

    
    for(auto i : arguments)
    {
        std::cout << i->str() << '\n';
    }

    command->internal_proc(arguments);

    return true;
}

std::shared_ptr<Command> CommandBuilder::findFirstCandidate(const std::vector<std::shared_ptr<Command>> &cmds, int argSize)
{
    for(const auto& cmd : cmds)
    {
        if(cmd->getArgumentCount() == argSize)
        {
            return cmd;
        }
    }
    return nullptr;
}
} // namespace dppcord