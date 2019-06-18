/**
 * @file WrappedCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef WRAPPEDCOMMAND_HPP
#define WRAPPEDCOMMAND_HPP

#include "Command.hpp"

namespace dppcord
{

class WrappedCommand : public Command
{
public:
    WrappedCommand() = default;
    virtual ~WrappedCommand() = default;

    virtual void proc(const BaseMessage& pMsg, const ArgumentList& cmd){}

    void internal_proc(const BaseMessage& pMsg, const ArgumentList& cmd) override
    {
        proc(pMsg, cmd);
    }
};
} // namespace dppcord

#endif