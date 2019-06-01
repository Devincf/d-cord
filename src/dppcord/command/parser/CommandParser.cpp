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
#include "dppcord/command/builder/CommandBuilder.hpp"

namespace dppcord
{
    ParsedCommand CommandParser::parse(const std::string& cmdStr)
    {
        //std::cout << "Parsing arguments of command string(" << cmdStr << ")...";
        std::vector<std::string> split_cmdStr;
        boost::split(split_cmdStr, cmdStr, boost::is_any_of(" "));

        ParsedCommand cmd;
        
        for (auto it = split_cmdStr.begin() + 1; it != split_cmdStr.end(); it++)
        {
            cmd.argList.addArgument(Argument(*it));
            //Todo change back to argument deduction
            // Currently only parsing Arguments as String until I find a good alternative for the argument::get() function
            /*if (*it == "true")
            {
                cmd.argList.addArgument(Argument(true));
            }
            else if (*it == "false")
            {
                cmd.argList.addArgument(Argument(false));
            }
            else
            {
                try
                {
                    double val = std::stod(*it);
                    cmd.argList.addArgument(Argument(val));
                }
                catch (const std::exception &e)
                {
                    cmd.argList.addArgument(Argument(*it));
                }
            }*/
        }
        cmd.name = CommandName(split_cmdStr[0]);

        //std::cout << "done\n";
        return cmd;
    }
}