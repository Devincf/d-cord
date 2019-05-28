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

#include "argument/IArgument.hpp"

namespace dppcord
{
    class Command
    {
        public:
        Command();
        Command(const std::string& name);
        ~Command();
        std::string get();
        void addArgument(IArgument* pArg);
        private:
        std::vector<IArgument*> m_args;
        CommandName m_cmdName;
    };
}

#endif