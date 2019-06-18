/**
 * @file LambdaCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LAMBDACOMMAND_HPP
#define LAMBDACOMMAND_HPP

#include "Command.hpp"

namespace dppcord
{
class BaseMessage;
class ParsedCommand;
class LambdaCommand : public Command
{
public:
    LambdaCommand()=default;
    LambdaCommand(const callback& f) : fn(f) {}
    ~LambdaCommand() = default;

    void internal_proc(const BaseMessage& pClient, const ArgumentList& cmd) override
    {
        fn(pClient, cmd);
    }

    callback fn;
};
} // namespace dppcord

#endif