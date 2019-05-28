/**
 * @file CommandName.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 02:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMANDNAME_HPP
#define COMMANDNAME_HPP

#include <string>

namespace dppcord
{
    class CommandName
    {
        public:
        CommandName(){}
        CommandName(const char * iname): name(iname){}
        CommandName(const std::string& iname):name(iname){}
        CommandName& operator=(const char* rhs)
        {
            name = rhs;
            return *this;
        }
        CommandName& operator=(const std::string& rhs)
        {
            name = rhs;
            return *this;
        }
        CommandName& operator=(const std::string&& rhs)
        {
            name = rhs;
            return *this;
        }
        ~CommandName(){}
        std::string name;
    };
}

#endif