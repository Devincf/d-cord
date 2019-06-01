/**
 * @file Command.hpp
 * 
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 09:46
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "CommandName.hpp"
#include "dppcord/command/argument/ArgumentList.hpp"
#include "util.hpp"

namespace dppcord
{
    class Command
    {
        public:
        Command() = default;
        Command(const std::string& name);
        virtual ~Command() = default;

        virtual void internal_proc(BaseMessage* pMsg, const ArgumentList& argList);

        private:
        CommandName m_cmdName;
    };
}

#endif