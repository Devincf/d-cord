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

#include "dppcord/core/objects/message/BaseMessage.hpp"

namespace dppcord
{


bool CommandBuilder::tryBuildCommand(BaseMessage* pMsg)
{
    //std::cout << "parsing arguments";
    auto parsedCommand = CommandParser::parse(pMsg->content());
    //std::cout << "searching for command " << parsedCommand.name.name << "...\n";
    auto arguments = parsedCommand.argList.getArguments();

    auto commands = CommandMap::getCommand(parsedCommand.name.name);
    
    if (commands.size() == 0)
        return false; // Command doesnt exist.
    auto command = commands[0];

    if(command == nullptr)
        return false;

    command->internal_proc(pMsg, parsedCommand.argList);

    return true;
}
} // namespace dppcord