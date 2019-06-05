/**
 * @file discordclient.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Discord client for accessing the discord api
 * @version 0.1
 * @date 2019-05-17 05:29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISCORDCLIENT_HPP
#define DISCORDCLIENT_HPP

#include "dppcord/core/handler/GuildsHandler.hpp"
#include "dppcord/core/handler/UsersHandler.hpp"
#include "dppcord/core/objects/user/BotUser.hpp"

#include "dppcord/database/Database.hpp"

#include "dppcord/plugin/IPlugin.hpp"

#include "dppcord/websocket/WebsocketHandler.hpp"

namespace dppcord
{
class DiscordClient
{
public:
    /**
     * @brief Construct a new Discord Client object
     * deleted so its only possible to create a Discord Client with a token
     */
    DiscordClient() = delete;
    /**
     * @brief Destroy the Discord Client object
     */
    virtual ~DiscordClient();
    /**
     * @brief Construct a new Discord Client object
     * @param token - discord api token
     */
    DiscordClient(const std::string &token);
    /**
     * @brief Get the Users Handler object
     * @return Pointer to the UsersHandler object
     */
    UsersHandler& getUsersHandler();
    /**
     * @brief Get the Guilds Handler object
     * @return Pointer to the GuildsHandler object
     */
    GuildsHandler& getGuildsHandler();
    /**
     * @brief Get the Websocket Handler object
     * @return Pointer to the WebsocketHandler object
     */
    WebsocketHandler& getWebsocketHandler();
    /**
     * @brief Get the Bot User object
     * @return BotUser& 
     */
    BotUser& getBotUser();
    /**
     * @brief Get the database object
     * @return const SQLiteDatabase& 
     */
    Database& getDatabase();
    /**
     * @brief Returns the token of the bot
     * @return std::string 
     */
    std::string getToken() const;
    /**
     * @brief Starts the bot
     */
    void run();
    /**
     * @brief Shuts the bot down 
     */
    void shutdown();
    /**
     * @brief Restarts the Bot
     */
    void restart();

    template <typename T>
    void loadPlugin()
    {
        m_plugins.push_back(std::make_unique<T>(this));
        m_plugins.back()->init();
    }

    const bool isPluginLoaded(const std::string& pluginName) const;

    bool running;

private:
    /**
     * @brief discordapi token used for interaction with the discord api
     */
    std::string m_discordtoken;
    /**
     * @brief Handler containing all the guilds the bot is in with helper functions
     */
    GuildsHandler m_guildHandler;
    /**
     * @brief Handler containing all the users the bot has some kind of connection with
     */
    UsersHandler m_userHandler;
    /**
     * @brief Handler that does all the internal Websocket connection related stuff
     */
    WebsocketHandler m_websockethandler; //change to gatewaymanager
    /**
     * @brief Database wrapper class 
     * Todo: use templates for easy switch between different database systems
     */
    std::unique_ptr<Database> m_database;
    /**
     * @brief Vector containing all the loaded plugins
     */
    std::vector<std::unique_ptr<IPlugin>> m_plugins;
    /**
     * @brief The bot user object
     */
    BotUser m_botUser;
};
} // namespace dppcord

#endif