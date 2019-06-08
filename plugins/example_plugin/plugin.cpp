/**
 * @file plugin.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 10:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "plugin.hpp"

#include <iostream>

const nlohmann::json ExamplePlugin::defaultConfig={
        {"pluginname", "Money System"},
        {"plugindesc", "Virtual money system for discord"},
        {"pluginver", "1.0"}
    };

ExamplePlugin::ExamplePlugin(DiscordClient *pClient) : IPlugin(pClient, "Example Plugin")
{
    std::cout << "Example Plugin loaded\n";
}
ExamplePlugin::~ExamplePlugin() {}

void ExamplePlugin::init() {}
void ExamplePlugin::shutdown() {}