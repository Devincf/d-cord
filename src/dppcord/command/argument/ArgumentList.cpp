/**
 * @file ArgumentList.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-01 02:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/argument/ArgumentList.hpp"

namespace dppcord
{


    const Argument& ArgumentList::operator[](int index) const
    {
        return m_arguments[index];
    }

    void ArgumentList::addArgument(const Argument& arg)
    {
        m_arguments.push_back(arg);
    }

    std::vector<Argument> ArgumentList::getArguments() const
    {
        return m_arguments;
    }
}