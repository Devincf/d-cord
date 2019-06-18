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

#include "dppcord/core/objects/user/BotUser.hpp"
#include "dppcord/core/config/ConfigData.hpp"

#include "dppcord/core/objects/guild/Guild.hpp"
#include "dppcord/core/objects/user/User.hpp"
#include "dppcord/core/objects/channel/DmChannel.hpp"

#include "dppcord/database/Database.hpp"

#include "dppcord/plugin/IPlugin.hpp"

#include "dppcord/websocket/WebsocketHandler.hpp"



namespace dppcord
{
class DiscordClient
{
public:
    /**
     * @brief Destroy the Discord Client object
     */
    virtual ~DiscordClient();
    /**
     * @brief Construct a new Discord Client object
     * @param token - discord api token
     */
    DiscordClient();
    /**
     * @brief Get the Users Handler object
     * @return Pointer to the UsersHandler object
     */
    //UsersHandler& getUsersHandler();
    /**
     * @brief Get the Guilds Handler object
     * @return Pointer to the GuildsHandler object
     */
    //GuildsHandler& getGuildsHandler();
    /**
     * @brief Get the Websocket Handler object
     * @return Pointer to the WebsocketHandler object
     */
    WebsocketHandler& getWebsocketHandler();
    /**
     * @brief Get the Bot User object
     * @return BotUser& 
     */
    BotUser* getBotUser()const;
    void setBotUser(BotUser* pUser);
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

    DmChannel* addDmChannel(const nlohmann::json& channeljson);

    /**
     * @brief Adds a guild into map through a pointer to a guild
     * @param rGuild Guild to be added
     * @return the new guild object
     */
    Guild& addGuild(Guild * const rGuild);
    /**
     * @brief Adds a guild into map through a json data object
     * @param json containing guild data
     * @return the new guild object
     */
    Guild& addGuild(const nlohmann::json& guildjson);

    /**
     * @brief Returns a pointer to the guild with a given id
     * @param id of the guild
     * @return Guild* , nullptr if no guild was found
     */
    Guild& getGuild(const Snowflake& id) const;
    /**
     * @brief Returns the Amount of Guilds
     * @return const int 
     */
    const int guildAmount() const;

    /**
     * @brief Adds a user into the global User map
     * @param pointer to the User object that should be inserted.
     * @return Whether the User didnt exist in the map before
     */
    const bool addUser(User * const pUser);
    /**
     * @brief Checks whether a User id exists in the global user map
     * @param id to look for
     * @return std::shared_ptr<User> of the user. nullptr if no user was found
     */
    User& findUser(const Snowflake& id) const;
    /**
     * @brief Checks whether a User exists or not
     * @param id of the user
     * @return bool true if user exists
     */
    const bool userExists(const Snowflake& id) const;
    /**
     * @brief Returns the total amount of global Users
     * @return const int 
     */
    const int userAmount() const;

    template <typename T>
    void loadPlugin()
    {
        std::unique_ptr<IPlugin> plugin = std::make_unique<T>(this);
        plugin->init();
        ConfigData::addPluginConfig(plugin->getName(), plugin->getDefaultConfig());
        m_plugins.push_back(std::move(plugin));
        //load config plugin->getDefault()
    }

    const bool isPluginLoaded(const std::string& pluginName) const;

    bool running;

private:
    /**
     * @brief discordapi token used for interaction with the discord api
     */
    std::string m_discordtoken;
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
     * @brief Map containing all guilds
     */
    std::map<Snowflake,std::unique_ptr<Guild>> m_guilds;
    /**
     * @brief Map containing all users
     */
    std::map<Snowflake,std::unique_ptr<User>> m_users;
    /**
     * @brief Map containing all dm channels
     */
    std::map<Snowflake,std::unique_ptr<DmChannel>> m_dmchannels;
    /**
     * @brief The bot user object
     */
    BotUser* m_botUser;
};
} // namespace dppcord

#endif