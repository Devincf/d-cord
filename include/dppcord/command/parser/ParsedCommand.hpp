/**
 * @file ParsedCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 11:06
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PARSEDCOMMAND_HPP
#define PARSEDCOMMAND_HPP

#include <vector>
#include <memory>

#include "dppcord/command/CommandName.hpp"
#include "dppcord/command/argument/IArgument.hpp"

namespace dppcord
{
struct ParsedCommand
{
    std::vector<std::shared_ptr<IArgument>> arguments;
    CommandName name;
};

} // namespace dppcord

#endif