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
#include <vector>
#include <memory>

#include "argument/IArgument.hpp"

namespace dppcord
{
    class Command
    {
        public:
        Command() = default;
        Command(const std::string& name);
        virtual ~Command() = default;
        virtual int getArgumentCount();

        virtual void internal_proc(const std::vector<std::shared_ptr<IArgument>>& args);

        protected:

        int m_argAmount;

        private:
        CommandName m_cmdName;
    };
}

#endif