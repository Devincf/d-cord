/**
 * @file plugin.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 10:20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/plugin/IPlugin.hpp"

using namespace dppcord;

class ExamplePlugin : public IPlugin
{
    public:
    ExamplePlugin(DiscordClient* pClient);
    ~ExamplePlugin();

    const nlohmann::json& getDefaultConfig() override { return defaultConfig;}

    void init()override;
    void shutdown() override;
    private:

    static const nlohmann::json defaultConfig;
};