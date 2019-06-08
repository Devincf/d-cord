/**
 * @file IPlugin.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 10:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef IPLUGIN_HPP
#define IPLUGIN_HPP
#include "nlohmann/json.hpp"

namespace dppcord
{
class DiscordClient;
class IPlugin
{
public:
    virtual ~IPlugin() = default;
    IPlugin();

    virtual void init();
    virtual void shutdown();
    const std::string& getName() const;
    virtual const nlohmann::json& getDefaultConfig() = 0;

protected:
    IPlugin(DiscordClient *pClient, const std::string &name);
    std::string m_name;
    DiscordClient *m_pClient;
};
} // namespace dppcord

#endif