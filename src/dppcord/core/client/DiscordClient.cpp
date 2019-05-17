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


namespace dppcord
{
    DiscordClient::DiscordClient(const std::string& token): m_discordtoken(token), m_websockethandler(token)
    {
        m_websockethandler.init();
    }

    DiscordClient::~DiscordClient()
    {

    }
}