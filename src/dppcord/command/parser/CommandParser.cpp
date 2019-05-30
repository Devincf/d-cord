/**
 * @file CommandParser.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 04:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/command/parser/CommandParser.hpp"
#include "dppcord/command/argument/StringArgument.hpp"
#include "dppcord/command/argument/DecimalArgument.hpp"
#include "dppcord/command/argument/BoolArgument.hpp"
#include "dppcord/command/builder/CommandBuilder.hpp"

namespace dppcord
{
    ParsedCommand CommandParser::parse(const std::string& cmdStr)
    {
        std::cout << "Parsing arguments of command string(" << cmdStr << ")...";
        std::vector<std::string> split_cmdStr;
        boost::split(split_cmdStr, cmdStr, boost::is_any_of(" "));

        ParsedCommand cmd;
        cmd.arguments = std::vector<std::shared_ptr<IArgument>>();
        
        for (auto it = split_cmdStr.begin() + 1; it != split_cmdStr.end(); it++)
        {
            std::shared_ptr<IArgument> arg = nullptr;
            if (*it == "true")
            {
                arg = std::make_shared<BoolArgument>(true);
            }
            else if (*it == "false")
            {
                arg = std::make_shared<BoolArgument>(false);
            }
            else
            {
                try
                {
                    double val = std::stod(*it);
                    arg = std::make_shared<DecimalArgument>(val);
                }
                catch (const std::exception &e)
                {
                    arg = std::make_shared<StringArgument>(*it);
                }
            }

            cmd.arguments.push_back(arg);
        }
        cmd.name = CommandName(split_cmdStr[0]);

        std::cout << "done\n";
        return cmd;
    }
}