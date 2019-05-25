/**
 * @file Guild.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 08:22
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/guild/Guild.hpp"

#include "dppcord/util/jsonutil.hpp"

#include "dppcord/core/objects/user/UsersHandler.hpp"

#include <string>

namespace dppcord
{
Guild::Guild() {}
Guild::~Guild() {}

Guild::Guild(const nlohmann::json &guildjson, UsersHandler *pUserHandler)
{
    m_afkChannel = nullptr;
    m_systemChannel = nullptr;
    m_ownerPtr = nullptr;
    m_embedChannel = nullptr;
    m_widgetChannel = nullptr;

    m_id = tryGetSnowflake("id", guildjson);
    m_name = tryGetJson<std::string>("name", guildjson);
    m_iconHash = tryGetJson<std::string>("icon", guildjson);
    m_splashHash = tryGetJson<std::string>("splash", guildjson);
    m_owner = tryGetJson<bool>("owner", guildjson, false);
    //m_ownerPtr = tryGetSnowflake("owner_id", guildjson);
    m_permissions = tryGetJson<int>("permissions", guildjson);
    m_region = tryGetJson<std::string>("region", guildjson);
    //m_afkChannelId = tryGetSnowflake("afk_channel_id", guildjson);
    m_afkTimeout = tryGetJson<int>("afk_timeout", guildjson);
    m_embedEnabled = tryGetJson<bool>("embed_enabled", guildjson);
    //m_embedChannelId = tryGetSnowflake("embed_channel_id", guildjson);
    m_verificationLevel = tryGetJson<int>("verification_level", guildjson);
    m_defaultMessageNotifications = tryGetJson<int>("default_message_notifications", guildjson);
    m_explicitContentFilter = tryGetJson<int>("explicit_content_filter", guildjson);

    for (auto it = guildjson["roles"].begin(); it != guildjson["roles"].end(); it++)
    {
        m_roles.insert({(*it)["id"], std::shared_ptr<Role>(new Role(*it))});
    }
    for (auto it = guildjson["emojis"].begin(); it != guildjson["emojis"].end(); it++)
    {
        m_emojis.push_back(Emoji(*it));
    }

    //features
    m_mfaLevel = tryGetJson<int>("mfa_level", guildjson);
    m_applicationId = tryGetSnowflake("application_id", guildjson);
    m_widgetEnabled = tryGetJson<bool>("widget_enabled", guildjson);
    //m_widgetChannelId = tryGetSnowflake("widget_channel_id", guildjson);
    //m_systemChannelId = tryGetSnowflake("system_channel_id", guildjson);
    //joined_at
    m_large = tryGetJson<bool>("large", guildjson);
    m_unavailable = tryGetJson<bool>("unavailable", guildjson);
    m_memberCount = tryGetJson<int>("member_count", guildjson);
    //voice states
    //std::cout << "loading members\n";
    if (pUserHandler == nullptr)
    {
        //implement users locally
        for (auto it = guildjson["members"].begin(); it != guildjson["members"].end(); it++)
        {
            auto ptr = std::shared_ptr<User>(new GuildUser(this, *it));
            m_members.push_back(ptr);
            if (ptr->getId() == tryGetSnowflake("owner_id", guildjson))
            {
                m_ownerPtr = ptr;
            }
        }
    }
    else
    {
        for (auto it = guildjson["members"].begin(); it != guildjson["members"].end(); it++)
        {
            auto userptr = pUserHandler->findUser(tryGetSnowflake("id", (*it)["user"]));
            if (userptr == nullptr)
            {
                userptr = std::shared_ptr<User>(new GuildUser(this, *it));
                pUserHandler->addUser(userptr->getId(), userptr);
            }
            m_members.push_back(userptr);

            if (userptr->getId() == tryGetSnowflake("owner_id", guildjson))
            {
                m_ownerPtr = userptr;
            }
        }
    }

    //std::cout << "loading channels\n";
    for (auto it = guildjson["channels"].begin(); it != guildjson["channels"].end(); it++)
    {
        auto ptr = std::shared_ptr<Channel>(new Channel(this, *it));
        m_channels.push_back(ptr);
        if (ptr->getId() == tryGetSnowflake("afk_channel_id", guildjson))
        {
            m_afkChannel = ptr.get();
            continue;
        }
        else if (ptr->getId() == tryGetSnowflake("embed_channel_id", guildjson))
        {
            m_embedChannel = ptr.get();
            continue;
        }
        else if (ptr->getId() == tryGetSnowflake("widget_channel_id", guildjson))
        {
            m_widgetChannel = ptr.get();
            continue;
        }
        else if (ptr->getId() == tryGetSnowflake("system_channel_id", guildjson))
        {
            m_systemChannel = ptr.get();
            continue;
        }
    }
    //std::cout << "loading done\n";
    //presences
    m_maxPresences = tryGetJson<int>("max_presences", guildjson);
    m_maxMembers = tryGetJson<int>("max_members", guildjson);
    m_vanityUrlCode = tryGetJson<std::string>("vanity_url_code", guildjson);
    m_description = tryGetJson<std::string>("description", guildjson);
    m_banner = tryGetJson<std::string>("banner", guildjson);
    /*
    if (m_afkChannel)
        std::cout << "Afk channelid: " << m_afkChannel->getName() << '\n';
    if (m_embedChannel)
        std::cout << "embed channelid: " << m_embedChannel->getName() << '\n';
    if (m_systemChannel)
        std::cout << "system channelid: " << m_systemChannel->getName() << '\n';
    if (m_widgetChannel)
        std::cout << "widget channelid: " << m_widgetChannel->getName() << '\n';
    if (m_ownerPtr)
        std::cout << "owner id: " << std::to_string(m_ownerPtr->getId()) << '\n';*/
}

Snowflake Guild::getId() { return m_id; }

std::shared_ptr<Role> Guild::getRole(const Snowflake &id)
{
    auto roleptr = m_roles.find(id);
    if(roleptr == m_roles.end())
    {
        return nullptr;
    }
    return roleptr->second;
}
} // namespace dppcord