/**
 * @file DecimalArgument.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 04:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/argument/DecimalArgument.hpp"

namespace dppcord
{
    DecimalArgument::DecimalArgument(){}
    DecimalArgument::DecimalArgument(const char* charptr)
    {
        try
        {
            m_val = std::stod(charptr);
        }
        catch(const std::exception& e)
        {
            //couldnt parse str to double;
        }
    }

    DecimalArgument::~DecimalArgument(){}

    std::string DecimalArgument::str()
    {
        return "DecimalArgument(" + std::to_string(m_val) + ")";
    }
}