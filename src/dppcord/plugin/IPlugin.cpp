/**
 * @file IPlugin.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 10:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/plugin/IPlugin.hpp"

#include <functional>

namespace dppcord
{
    IPlugin::IPlugin(DiscordClient* pClient, const std::string& name):  m_name(name)
    {
        m_pClient = pClient;
    }
    IPlugin::IPlugin(): m_name(""), m_pClient(nullptr){}
    void IPlugin::init(){}
    void IPlugin::shutdown(){}
    const std::string& IPlugin::getName() const {return m_name;}
}