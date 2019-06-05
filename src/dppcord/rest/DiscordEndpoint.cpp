/**
 * @file DiscordEndpoint.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 04:21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "dppcord/rest/Request.hpp"

#include <iostream>

namespace dppcord
{
std::string DiscordEndpoint::token = "";

void DiscordEndpoint::init(const std::string &itoken)
{
    token = itoken;
}

std::string DiscordEndpoint::sendMessage(const Snowflake &channelId, const std::string &content)
{
    return sendMessageExtended(channelId, {{"content", content}});
}

std::string DiscordEndpoint::sendMessageExtended(const Snowflake& channelId, const nlohmann::json& json)
{
    RequestHeaderList rhl;
    rhl.setContent(REQUESTCONTENT_MULTIPART_FORMDATA).addHeader("Authorization: Bot " + token);
    RequestContent rc(json);

    auto response = Request::sendPOST(//this should be post?
        apiBase + "channels/" + std::to_string(channelId) + "/messages",
        rhl,
        rc);
    return response.get();
}

std::string DiscordEndpoint::deleteMessage(const std::string &channel, const std::string &id)
{
    RequestHeaderList rhl;
    rhl.setContent(REQUESTCONTENT_MULTIPART_FORMDATA).addHeader("Authorization: Bot " + token);

    auto response = Request::sendDELETE(
        apiBase + "channels/" + channel + "/messages/" + id,
        rhl
    );
    return response.get();
}

std::string DiscordEndpoint::createReaction(const std::string& channelId, const std::string& msgId, const std::string& emojiNameId)
{
    //PUT/channels/{channel.id}/messages/{message.id}/reactions/{emoji}/@me
    RequestHeaderList rhl;
    rhl.setContent(REQUESTCONTENT_MULTIPART_FORMDATA).addHeader("Authorization: Bot " + token).addHeader("Content-Length:0");
    auto response = Request::sendPUT(
        apiBase + "channels/" + channelId +"/messages/"+ msgId + "/reactions/"+ emojiNameId + "/@me",
        rhl
    );

    return response.get();
}
} // namespace dppcord