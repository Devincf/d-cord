/**
 * @file StringArgument.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 04:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/argument/StringArgument.hpp"

namespace dppcord
{
    StringArgument::StringArgument(){}
    StringArgument::StringArgument(const char* str): Argument(std::string(str)){}
    StringArgument::~StringArgument(){}

    StringArgument& StringArgument::operator=(const char* rhs)
    {
        StringArgument(std::string(rhs));
        return *this;
    }

    std::string StringArgument::str()
    {
        return "StringArgument(" + m_val +")";
    }
}