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

#include "dppcord/command/builder/CommandMap.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"


#include "dppcord/database/SQLiteDatabase.hpp"

#include "dppcord/util/constants/config.hpp"

namespace dppcord
{
DiscordClient::DiscordClient(const std::string &token) : m_discordtoken(token), m_websockethandler(token, this)
{
    m_database = std::unique_ptr<Database>(new SQLiteDatabase("test.db"));

    ConfigData::readConfig("main", config::main);

    CommandMap::addCommand("!about", [&](const BaseMessage &msg, const ArgumentList &argList) {
        nlohmann::json json2{
            {"embed",
             {
                 {"color", 15794175},
                 {"title", ":gem:  About "},
                 {"description", "• Developer : <@!142733073262444545>「**Luminous#6996**」\n"
                                 "• Invite Link : To be added \n"
                                 "• Current Version : Beta 1.0.0\n"
                                 "• Developed in **C++** using [**d++cord**](https://github.com/Devincf/d-cord)\n"
                                 "• Active in : **" +
                                     std::to_string(m_guildHandler.amount()) + "** servers with a total of **" + std::to_string(m_userHandler.globalAmount()) + "** users"},

             }} // namespace dppcord
        };
        msg.channel().sendMessageExtended(json2);
    });
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
    do
    {
        std::cout << "initializing\n";
        m_websockethandler.init();
        m_websockethandler.wait();
        std::cout << "wait done\n";
        m_websockethandler.shutdown();
    } while (running);
}

const bool DiscordClient::isPluginLoaded(const std::string &pluginName) const
{
    for (auto i = 0; i < m_plugins.size(); i++)
    {
        if (m_plugins[i]->getName() == pluginName)
        {
            return true;
        }
    }
    return false;
}

WebsocketHandler &DiscordClient::getWebsocketHandler() { return m_websockethandler; }
GuildsHandler &DiscordClient::getGuildsHandler() { return m_guildHandler; }
UsersHandler &DiscordClient::getUsersHandler() { return m_userHandler; }
std::string DiscordClient::getToken() const { return m_discordtoken; }
Database &DiscordClient::getDatabase() { return *m_database; }
BotUser &DiscordClient::getBotUser() { return m_botUser; }
} // namespace dppcord