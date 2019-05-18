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
     * 
     */
    virtual ~DiscordClient();
    /**
     * @brief Construct a new Discord Client object
     * 
     * @param token - discord api token
     */
    DiscordClient(const std::string &token);

private:
    /**
     * @brief discordapi token used for interaction with the discord api
     */
    std::string m_discordtoken;
    /**
     * @brief Handler that does all the internal Websocket connection related stuff
     */
    WebsocketHandler m_websockethandler; //change to gatewaymanager
};
} // namespace dppcord

#endif