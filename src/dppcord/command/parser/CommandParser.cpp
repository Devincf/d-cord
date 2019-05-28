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

namespace dppcord
{
    std::unique_ptr<Command> CommandParser::parse(const std::string& cmdStr)
    {
        
        std::cout << "Parsing command string(" << cmdStr << ")...";


        std::vector<std::string> split_cmdStr;
        boost::split(split_cmdStr, cmdStr, boost::is_any_of(" "));

        std::unique_ptr<Command> cmd = std::unique_ptr<Command>(new Command(split_cmdStr[0]));
        
        for (auto it = split_cmdStr.begin() + 1; it != split_cmdStr.end(); it++)
        {
            IArgument *arg = nullptr;
            if (*it == "true")
            {
                arg = new BoolArgument(true);
            }
            else if (*it == "false")
            {
                arg = new BoolArgument(false);
            }
            else
            {
                try
                {
                    double val = std::stod(*it);
                    arg = new DecimalArgument(val);
                }
                catch (const std::exception &e)
                {
                    arg = new StringArgument(*it);
                }
            }

            cmd->addArgument(arg);
        }


        std::cout << "done\n";
        return cmd;
    }
}