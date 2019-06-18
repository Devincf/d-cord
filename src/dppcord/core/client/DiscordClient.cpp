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
#include "dppcord/core/objects/channel/TextChannel.hpp"

#include "dppcord/database/SQLiteDatabase.hpp"
#include "dppcord/util/jsonutil.hpp"
#include "dppcord/util/constants/config.hpp"

namespace dppcord
{
DiscordClient::DiscordClient() : m_websockethandler(this)
{
    m_database = std::unique_ptr<Database>(new SQLiteDatabase("test.db"));

    ConfigData::readConfig("main", config::main);

    m_discordtoken = ConfigData::get("discord_token");
    if (m_discordtoken == "ENTER TOKEN HERE")
        throw std::invalid_argument("No token entered, please specify your discord token inside the config.json and restart");

    m_websockethandler.setToken(m_discordtoken);

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
                                     std::to_string(guildAmount()) + "** servers with a total of **" + std::to_string(userAmount()) + "** users"},

             }} // namespace dppcord
        };
        TextChannel &channel = dynamic_cast<TextChannel &>(msg.channel());
        channel.sendMessageExtended(json2);
    });
    DiscordEndpoint::init(m_discordtoken);
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

DmChannel *DiscordClient::addDmChannel(const nlohmann::json &channeljson)
{
    auto id = tryGetSnowflake("id", channeljson);
    auto res = m_dmchannels.insert({id, std::make_unique<DmChannel>(channeljson)});
    if(!res.second) std::cout << "channel already existed.\n";
    return res.first->second.get();
}

DmChannel *DiscordClient::getDmChannel(const Snowflake &id)
{
    auto ptr = m_dmchannels.find(id);
    if(ptr == m_dmchannels.end())
    {
        return nullptr;
    }
    return ptr->second.get();
}

Guild &DiscordClient::addGuild(Guild *const rGuild)
{
    auto res = m_guilds.insert({rGuild->getId(), std::unique_ptr<Guild>(rGuild)});
    if (!res.second)
        throw std::runtime_error("Guild" + std::to_string(rGuild->getId()) + " already existed");

    return *res.first->second;
}
Guild &DiscordClient::addGuild(const nlohmann::json &guildjson)
{
    auto res = m_guilds.insert({tryGetSnowflake("id", guildjson), std::make_unique<Guild>(guildjson)});
    if (!res.second)
        throw std::runtime_error("Guild" + std::to_string(res.first->second->getId()) + " already existed");

    Guild *guild = res.first->second.get();
    for (const auto &userjson : guildjson["members"])
    {
        Snowflake userid = tryGetSnowflake("id", userjson["user"]);
        User *user;

        auto ptr = m_users.find(userid);
        if (ptr == m_users.end())
        {
            user = new GuildUser(guild, userjson);
            addUser(user);
        }
        else
        {
            user = ptr->second.get();
        }
        guild->addUser(user);

        if (userid == tryGetSnowflake("owner_id", guildjson))
        {
            User *owner = guild->getOwner();
            owner = user;
        }
    }

    return *res.first->second;
}

const bool DiscordClient::addUser(User *const pUser)
{
    auto res = m_users.insert({pUser->getId(), std::unique_ptr<User>(pUser)});
    if (!res.second)
    {
        //already existed
        return false;
    }
    return true;
}

const int DiscordClient::userAmount() const
{
    return m_users.size();
}

const bool DiscordClient::userExists(const Snowflake &id) const
{
    return m_users.find(id) != m_users.end();
}

User &DiscordClient::findUser(const Snowflake &id) const
{
    auto it = m_users.find(id);
    if (it == m_users.end())
        throw std::runtime_error("User with id " + std::to_string(id) + " not found");
    if (!it->second)
        throw std::runtime_error("User is nullptr");
    return *it->second;
}

const int DiscordClient::guildAmount() const
{
    return m_guilds.size();
}

Guild &DiscordClient::getGuild(const Snowflake &id) const
{
    auto ptr = m_guilds.find(id);

    if (ptr == m_guilds.end())
        throw std::runtime_error("Guild not found");
    if (!ptr->second)
        throw std::runtime_error("Guild is nullptr");

    return *ptr->second.get();
}

void DiscordClient::setBotUser(BotUser *pUser)
{
    m_botUser = pUser;
}

WebsocketHandler &DiscordClient::getWebsocketHandler() { return m_websockethandler; }
//UsersHandler &DiscordClient::getUsersHandler() { return m_userHandler; }
std::string DiscordClient::getToken() const { return m_discordtoken; }
Database &DiscordClient::getDatabase() { return *m_database; }
BotUser *DiscordClient::getBotUser() const { return m_botUser; }
} // namespace dppcord