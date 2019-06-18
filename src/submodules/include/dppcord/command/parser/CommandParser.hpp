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
#include "ParsedCommand.hpp"

#include <boost/algorithm/string.hpp>

#include <iostream>

namespace dppcord
{
class CommandParser
{
public:
    static ParsedCommand parse(const std::string &cmdStr);
};
} // namespace dppcord

#endif