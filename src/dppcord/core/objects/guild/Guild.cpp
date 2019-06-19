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

#include "dppcord/core/objects/channel/GuildVoiceChannel.hpp"
#include "dppcord/core/objects/channel/GuildTextChannel.hpp"
#include "dppcord/core/objects/channel/ChannelTypes.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include <string>

namespace dppcord
{
Guild::Guild() {}
Guild::~Guild() {}

Guild::Guild(const nlohmann::json &guildjson)
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
        m_roles.insert({(*it)["id"], std::forward<Role>(Role(this, *it))});
    }
    for (auto it = guildjson["emojis"].begin(); it != guildjson["emojis"].end(); it++)
    {
        if (it->find("user") != it->end())
            m_emojis.push_back(Emoji(&getUserFromId(tryGetSnowflake("id", (*it)["user"])), *it));
        else
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
    /*std::cout << "loading members\n";
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
    }*/
    //std::cout << "loading channels\n";
    for (auto it = guildjson["channels"].begin(); it != guildjson["channels"].end(); it++)
    {
        auto &channelptr = addChannel(*it);
        if (channelptr.getId() == tryGetSnowflake("afk_channel_id", guildjson))
        {
            m_afkChannel = &channelptr;
            continue;
        }
        else if (channelptr.getId() == tryGetSnowflake("embed_channel_id", guildjson))
        {
            m_embedChannel = &channelptr;
            continue;
        }
        else if (channelptr.getId() == tryGetSnowflake("widget_channel_id", guildjson))
        {
            m_widgetChannel = &channelptr;
            continue;
        }
        else if (channelptr.getId() == tryGetSnowflake("system_channel_id", guildjson))
        {
            m_systemChannel = &channelptr;
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

BaseChannel &Guild::addChannel(const nlohmann::json &channeldata)
{
    int type = tryGetJson<int>("type", channeldata);
    switch (type)
    {
    case CHANNELTYPE_GUILD_TEXT:
    {
        GuildTextChannel *channel = new GuildTextChannel(this, channeldata);
        return *m_channels.emplace_back(channel);
    }
    case CHANNELTYPE_GUILD_CATEGORY:
    {
        GuildChannel *channel = new GuildChannel(this, channeldata);
        return *m_channels.emplace_back(channel);
    }
    case CHANNELTYPE_GUILD_VOICE:
    {
        return *std::make_shared<GuildVoiceChannel>(this, channeldata);
    }
    default:
        throw std::runtime_error("[ERROR] Channel with type " + std::to_string(type) + "passed to Guild::addChannel id: " + std::to_string(tryGetSnowflake("id", channeldata)) + " this should never happen \n");
    }
}

BaseChannel &Guild::updateChannel(const nlohmann::json &channeldata)
{
    auto &channel = getChannel(tryGetSnowflake("id", channeldata));
    channel.update(channeldata);
    return channel;
}

const bool Guild::removeChannel(const Snowflake &id)
{
    auto channel = std::find_if(m_channels.begin(), m_channels.end(), [&id](std::unique_ptr<BaseChannel> &channel) { return channel->getId() == id; });
    if (channel == m_channels.end())
        return false;
    m_channels.erase(channel);
    return true;
}

Role &Guild::getRole(const Snowflake &id)
{
    auto roleptr = m_roles.find(id);
    if (roleptr == m_roles.end())
        throw std::runtime_error("Role with id " + std::to_string(id) + " wasn't found");
    return roleptr->second;
}

User &Guild::getUserFromId(const Snowflake &id) const
{
    for (const auto &it : m_members)
    {
        if (it->getId() == id)
        {
            return *it;
        }
    }
    //doesnt exist.
    throw std::runtime_error("User doesnt exist in guild map");
}

User &Guild::addUser(User *pUser)
{
    m_members.push_back(pUser);
    return *pUser;
}

const bool Guild::banUser(const Snowflake &id)
{
    auto user = std::find_if(m_members.begin(), m_members.end(), [&id](User *user) { return user->getId() == id; });
    if (user != m_members.end())
    {
        //ban
        std::cout << "banning " << std::to_string(id) << "...";
        return DiscordEndpoint::createGuildBan(std::to_string(m_id), std::to_string(id), {});
    }
    return false;
}

const void Guild::removeUser(const Snowflake &id)
{
    m_members.erase(std::remove_if(m_members.begin(), m_members.end(), [&id](User *user) { return user->getId() == id; }), m_members.end());
}

/*
void Guild::addMessage(BaseMessage* const msg)
{
    //std::cout << "adding message with id " << msg->getId(); 
    auto res = m_messages.insert({msg->getId(), std::shared_ptr<BaseMessage>(msg)}); 
    if(!res.second)
    {
        std::cout << "..error adding msg";
    }
    std::cout << '\n';
}

void Guild::removeMessage(const Snowflake& id)
{
    if(m_messages.erase(id) == 0)Todo: fix bug with shared_ptr not being copied correctly(?)
    {
        std::cout << "Tried deleting message with id " << id << " but it didnt exist. \n";
    }
}

BaseMessage& Guild::getMessage(const Snowflake &id)const
{
    auto msg = m_messages.find(id);
    if (msg == m_messages.end())
    {
        throw std::runtime_error("message with id " + std::to_string(id)+ " was not found\n");
    }
    return *msg->second;
}
*/
BaseChannel &Guild::getChannel(const Snowflake &id) const
{
    for (const auto &i : m_channels)
    {
        if (i->getId() == id)
        {
            return *i;
        }
    }
    throw std::runtime_error("Channel with id " + std::to_string(id) + " not found or is nullptr");
}

Emoji* Guild::getEmoji(const Snowflake& id)
{
    auto existing = std::find_if(m_emojis.begin(), m_emojis.end(), [&id](const Emoji& e) { return e.getId() == id; });
    if(existing == m_emojis.end()) return nullptr;
    return &(*existing);
}

void Guild::updateEmojis(const nlohmann::json &emojis)
{

    for (const auto &emoji : emojis)
    {
        auto id = tryGetSnowflake("id", emoji);
        Emoji* existing = getEmoji(id);
        if (existing == nullptr)
        {
            if (emoji.find("user") != emoji.end())
                m_emojis.emplace_back(&getUserFromId(tryGetSnowflake("id", emoji["user"])), emoji);
            else
                m_emojis.emplace_back(emoji);
        }else
        {
            existing->setValues(emoji);
        }
    }
}

User *Guild::getOwner() const { return m_ownerPtr; }

} // namespace dppcord