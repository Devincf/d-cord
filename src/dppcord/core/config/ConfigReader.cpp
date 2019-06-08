/**
 * @file ConfigReader.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-06 02:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/config/ConfigReader.hpp"

#include <string>
#include <fstream>
#include <streambuf>
#include <filesystem>
#include <iostream>

namespace dppcord
{

const nlohmann::json ConfigReader::readFile(const nlohmann::json &defaultConfig)
{
    if (std::filesystem::exists(configfilename))
    {
        std::ifstream t(configfilename);
        std::string conf((std::istreambuf_iterator<char>(t)),
                         std::istreambuf_iterator<char>());
                         t.close();
        if(conf.empty()) return nlohmann::json();
        return nlohmann::json::parse(conf);
    }
    else
    {
        std::ofstream ofs(configfilename);
        std::string s = defaultConfig.dump(4);
        std::copy(s.begin(), s.end(), std::ostreambuf_iterator<char>(ofs));
        ofs.close();
        return defaultConfig;
    }
}

const bool ConfigReader::writeFile(const std::string &str)
{
    std::ofstream ofs(configfilename);
    std::copy(str.begin(), str.end(), std::ostreambuf_iterator<char>(ofs));
    ofs.close();
    return true;
}
} // namespace dppcord