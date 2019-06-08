/**
 * @file ConfigReader.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-06 02:07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CONFIGREADER_HPP
#define CONFIGREADER_HPP

#include "nlohmann/json.hpp"

namespace dppcord
{

    static const std::string configfilename = "config.json";

    class ConfigReader
    {
        public:
        static const nlohmann::json readFile(const nlohmann::json& defaultConfig = {});
        static const bool writeFile(const std::string& str);
    };
}

#endif