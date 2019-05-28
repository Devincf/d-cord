/**
 * @file Command.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 04:14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/Command.hpp"

namespace dppcord
{
    Command::Command(){}
    Command::Command(const std::string& name):m_cmdName(name){}
    Command::~Command()
    {
        for(auto i : m_args)
        {
            delete i;
        }
    }

    void Command::addArgument(IArgument* pArg)
    {
        m_args.push_back(pArg);
    }

    std::string Command::get()
    {
        std::string retStr(m_cmdName.name + " >> ");
            int x  = 0;
            for(auto i : m_args)
            {
                retStr.append(" arg"+ std::to_string(++x) + " : " + i->str());
            }
            return retStr;
    }
}