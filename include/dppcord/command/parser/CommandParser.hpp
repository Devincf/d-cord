/**
 * @file CommandParser.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 02:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <string>
#include "../Command.hpp"

#include <boost/algorithm/string.hpp>
#include "../argument/StringArgument.hpp"
#include "../argument/DecimalArgument.hpp"
#include "../argument/BoolArgument.hpp"

#include <iostream>

namespace dppcord
{
class CommandParser
{
public:
    static std::unique_ptr<Command> parse(const std::string &cmdStr);
};
} // namespace dppcord

#endif