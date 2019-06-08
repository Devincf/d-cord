/**
 * @file ConfigData.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-06 02:07
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CONFIGDATA_HPP
#define CONFIGDATA_HPP

#include "nlohmann/json.hpp"

namespace dppcord
{
class ConfigData
{
public:
    static const bool addConfig(const std::string &&configName, const nlohmann::json &&defaultConfig = {});

    static const bool readConfig(const std::string &configName, const nlohmann::json &defaultConfig);
    static const bool addPluginConfig(const std::string &pluginName, const nlohmann::json &defaultConfig);
    
    static const bool reloadConfig();

    static const nlohmann::json& get(const std::string&& what);

    static nlohmann::json data;
};
} // namespace dppcord

#endif