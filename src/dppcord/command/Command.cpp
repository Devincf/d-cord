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
Command::Command(const std::string &name) : m_cmdName(name) {}

void Command::internal_proc(const std::vector<std::shared_ptr<IArgument>> &args)
{
}
int Command::getArgumentCount()
{
    return m_argAmount;
}
} // namespace dppcord