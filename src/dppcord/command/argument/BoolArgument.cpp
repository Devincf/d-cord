/**
 * @file BoolArgument.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 04:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/argument/BoolArgument.hpp"

namespace dppcord
{
BoolArgument::BoolArgument() {}
BoolArgument::~BoolArgument() {}

std::string BoolArgument::str()
{
    return "BoolArgument(" + std::string(((m_val) ? "true" : "false")) + ")";
}
} // namespace dppcord