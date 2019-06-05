/**
 * @file discordclient.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 05:35
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/database/SQLiteDatabase.hpp"

namespace dppcord
{
DiscordClient::DiscordClient(const std::string &token) : m_discordtoken(token), m_websockethandler(token, this)
{
    m_database = std::unique_ptr<Database>(new SQLiteDatabase("test.db"));
    DiscordEndpoint::init(token);
}

DiscordClient::~DiscordClient()
{
}

void DiscordClient::restart()
{
    m_websockethandler.shutdown();
}

void DiscordClient::shutdown()
{
    running = false;
    m_websockethandler.shutdown();
}

void DiscordClient::run()
{
    running = true;
    do{
        std::cout << "initializing\n";
        m_websockethandler.init();
        m_websockethandler.wait();
        std::cout << "wait done\n";
        m_websockethandler.shutdown();
    }while(running);
}

const bool DiscordClient::isPluginLoaded(const std::string& pluginName)
{
    for(auto i = 0;i< m_plugins.size();i++)
    {
        if(m_plugins[i]->getName() == pluginName)
        {
            return true;
        }
    }
    return false;
}

WebsocketHandler &DiscordClient::getWebsocketHandler() { return m_websockethandler; }
GuildsHandler &DiscordClient::getGuildsHandler() { return m_guildHandler; }
UsersHandler& DiscordClient::getUsersHandler(){return m_userHandler; }
std::string DiscordClient::getToken(){return m_discordtoken;}
Database* DiscordClient::getDatabase() {return m_database.get();}
BotUser& DiscordClient::getBotUser() { return m_botUser; }
} // namespace dppcord