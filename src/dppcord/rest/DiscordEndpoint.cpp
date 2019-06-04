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

namespace dppcord
{
    std::string DiscordEndpoint::token = "";

    void DiscordEndpoint::init(const std::string& itoken)
    {
        token = itoken;
    }

    std::string DiscordEndpoint::sendMessage(const Snowflake& channelId, const std::string& content)
    {
        RequestHeaderList rhl;
        rhl.setContent(REQUESTCONTENT_MULTIPART_FORMDATA).addHeader("Authorization: Bot " + token);
        nlohmann::json json;
        json["content"] = content;
        RequestContent rc(json);

        auto response = Request::sendGET(
            "https://discordapp.com/api/v6/channels/" + std::to_string(channelId) + "/messages",
            rhl,
            rc
            );
        return response.get();
    }
}