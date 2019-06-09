/**
 * @file ConfigData.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-06 02:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/config/ConfigData.hpp"

#include "dppcord/core/config/ConfigReader.hpp"

#include <memory>
#include <utility>
#include <iostream>
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
nlohmann::json ConfigData::data = nlohmann::json();

const bool ConfigData::addConfig(const std::string &&configName, const nlohmann::json &&defaultConfig)
{
    return defaultConfig; //addConfig(configName, defaultConfig);
}

const bool ConfigData::reloadConfig()
{
    data = ConfigReader::readFile();
    return true;
}

const nlohmann::json& ConfigData::get(const std::string&& what)
{
    return data[what];
}

const bool ConfigData::readConfig(const std::string &configName, const nlohmann::json &defaultConfig)
{
    if (data.empty())
    {
        data = ConfigReader::readFile(std::move(defaultConfig));
    }
    if (data.empty())
    {
        data = std::move(defaultConfig);
        ConfigReader::writeFile(defaultConfig.dump(4));
    }
    return true;
}

const bool ConfigData::addPluginConfig(const std::string &pluginName, const nlohmann::json &defaultConfig)
{
    if (data.empty())
    {
        readConfig(std::forward<const std::string>(pluginName), std::forward<const nlohmann::json>(defaultConfig));
    }

    if (data.find("plugins") != data.end() && data["plugins"].empty())
    {
        std::cout << "plugins wasnt set\n";
        data["plugins"] = {};
    }
    else
    {
        if (jsonIsSet(pluginName, data["plugins"]))
        {
            return true;
        }
    }
    data["plugins"][pluginName] = defaultConfig;
    return ConfigReader::writeFile(data.dump(4));
}

} // namespace dppcord