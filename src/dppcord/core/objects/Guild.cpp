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

#include "dppcord/core/objects/Guild.hpp"

#include "dppcord/util/jsonutil.hpp"

#include <string>

namespace dppcord
{
    Guild::Guild(){}
    Guild::~Guild(){}

    Guild::Guild(const nlohmann::json& guildjson)
    {
        m_id = tryGetSnowflake("id", guildjson);
        m_name = tryGetJson<std::string>("name", guildjson);
        m_iconHash = tryGetJson<std::string>("icon", guildjson);
        m_splashHash = tryGetJson<std::string>("splash", guildjson);
        m_owner = tryGetJson<bool>("owner", guildjson, false);
        m_ownerId = tryGetSnowflake("owner_id", guildjson);
        m_permissions = tryGetJson<int>("permissions", guildjson);
        m_region = tryGetJson<std::string>("region", guildjson);
        m_afkChannelId = tryGetSnowflake("afk_channel_id", guildjson);
        m_afkTimeout = tryGetJson<int>("afk_timeout", guildjson);
        m_embedEnabled = tryGetJson<bool>("embed_enabled", guildjson);
        m_embedChannelId = tryGetSnowflake("embed_channel_id", guildjson); 
        m_verificationLevel = tryGetJson<int>("verification_level", guildjson);
        m_defaultMessageNotifications = tryGetJson<int>("default_message_notifications",guildjson);
        m_explicitContentFilter = tryGetJson<int>("explicit_content_filter",guildjson);

        for(auto it = guildjson["roles"].begin();it!= guildjson["roles"].end();it++)
        {
            m_roles.push_back(Role(*it));
        }
        for(auto it = guildjson["emojis"].begin();it!= guildjson["emojis"].end();it++)
        {
            m_emojis.push_back(Emoji(*it));
        }

        //features
        m_mfaLevel = tryGetJson<int>("mfa_level", guildjson);
        m_applicationId = tryGetSnowflake("application_id", guildjson);
        m_widgetEnabled = tryGetJson<bool>("widget_enabled",guildjson);
        m_widgetChannelId = tryGetSnowflake("widget_channel_id", guildjson);
        m_systemChannelId = tryGetSnowflake("system_channel_id", guildjson);
        //joined_at
        m_large = tryGetJson<bool>("large", guildjson);
        m_unavailable = tryGetJson<bool>("unavailable", guildjson);
        m_memberCount = tryGetJson<int>("member_count",guildjson);
        //voice states
        //std::cout << "loading members\n";
        for(auto it = guildjson["members"].begin();it!= guildjson["members"].end();it++)
        {
            m_members.push_back(GuildUser(*it));
        }
        //std::cout << "loading channels\n";
        for(auto it = guildjson["channels"].begin();it!= guildjson["channels"].end();it++)
        {
            m_channels.push_back(Channel(*it));
        }
        //std::cout << "loading done\n";
        //presences
        m_maxPresences = tryGetJson<int>("max_presences", guildjson);
        m_maxMembers = tryGetJson<int>("max_members",guildjson);
        m_vanityUrlCode = tryGetJson<std::string>("vanity_url_code",guildjson);
        m_description = tryGetJson<std::string>("description",guildjson);
        m_banner = tryGetJson<std::string>("banner",guildjson);
    }
}