/**
 * @file GuildChannel.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 10:21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/channel/GuildChannel.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"
#include "dppcord/util/jsonutil.hpp"
#include "dppcord/rest/DiscordEndpoint.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"

namespace dppcord
{
GuildChannel::GuildChannel() {}
GuildChannel::GuildChannel(Guild *pGuild, const Document &channeljson) : BaseChannel(channeljson)
{
    m_guild = pGuild;
    m_name = tryGetJson<std::string>("name", channeljson);
    m_position = tryGetJson<int>("position", channeljson);
    m_nsfw = tryGetJson<bool>("nsfw", channeljson, false);
}
GuildChannel::~GuildChannel() {}

Guild *GuildChannel::getGuild() { return m_guild; }

std::shared_ptr<BaseMessage> GuildChannel::sendMessage(const std::string &msg)
{
    auto string = DiscordEndpoint::sendMessage(m_id, msg);
    auto json = Document::parse(string);
    std::shared_ptr<BaseMessage> m = std::make_shared<BaseMessage>(std::shared_ptr<BaseChannel>(this), json);
    m_guild->addMessage(m);
    return m;
}
} // namespace dppcord