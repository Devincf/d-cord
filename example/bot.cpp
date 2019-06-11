#include "bot.hpp"

#include <string>
#include <fstream>
#include <streambuf>

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"

#include "plugins/example_plugin/plugin.hpp"
#include "plugins/MoneySystem/plugin.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "nlohmann/json.hpp"

int main(int argc, char *argv[])
{
    std::ifstream t("token.txt");
    std::string token((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());

    Example e;

    /*auto test = e.getDatabase()->query("SELECT * FROM users");
    for (auto i : test)
    {
        for (const auto &[k, v] : i)
            std::cout << k << "-" << v << '\n';
    }*/

    dppcord::CommandMap::addCommand("!ping", [](const dppcord::BaseMessage& msg, const dppcord::ArgumentList &args) {
        msg.channel().sendMessage("pong").reactionListener(
            [](dppcord::BaseMessage &msg, const nlohmann::json &json) {
                std::cout << msg.content() << '\n';
                msg.channel().sendMessage("reacted to pong!");
            });
    });

    e.loadPlugin<ExamplePlugin>();
    e.loadPlugin<dppcord::plugins::moneysystem::MoneySystem>();

    /* auto test = DiscordEndpoint::getGuild("439065048628068363");
    nlohmann::json patchjson = {{"name", "modified"}};
    auto guildPatch = DiscordEndpoint::modifyGuild("439065048628068363", patchjson);
    auto getChannels = DiscordEndpoint::getGuildChannels("439065048628068363");
    nlohmann::json channelcreatejson = {{"name", "new_test"}};
    auto channelCreate = DiscordEndpoint::createGuildChannel("439065048628068363", channelcreatejson);
    nlohmann::json channelmodifyposjson = nlohmann::json::array();
    channelmodifyposjson.push_back({{"id", "565205398869508097"}, {"position", 11}});
    channelmodifyposjson.push_back({{"id", "565204674806808576"}, {"position", 10}});
    auto channelmodifypos = DiscordEndpoint::modifyGuildChannelPositions("439065048628068363", channelmodifyposjson);
    auto userList = DiscordEndpoint::getGuildUserList("439065048628068363");
    auto user = DiscordEndpoint::getGuildUser("439065048628068363", "142733073262444545");
    auto nicknameChange = DiscordEndpoint::modifyCurrentNick("439065048628068363", "cute bot owo :3");
    auto newRole = DiscordEndpoint::addGuildMemberRole("439065048628068363","539820462285389824", "576209601482063875");
    auto newRole = DiscordEndpoint::removeGuildMemberRole("439065048628068363","539820462285389824", "576209601482063875");
    std::string g = "439065048628068363";
    std::cout << DiscordEndpoint::getGuildRoles(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildPruneCount(g,100) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildVoiceRegions(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildInvites(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildIntegrations(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildEmbed(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildVanityURL(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildWidgetImage(g) << '\n';
    */

    //std::thread run(&Example::run, &e);
    std::string input;
    for(;;)
    {
        std::cin >> input;
        if(input== "random")
        {   
            std::cout << ConfigData::get("botdesc").get<std::string>() << '\n';
            ConfigData::reloadConfig();
            std::cout << ConfigData::get("botdesc").get<std::string>() << '\n';
        }
        else if(input == "exit")
        {
            std::cout << "Received Exit\n";
            e.shutdown();
            break;
        }else if(input == "retry")
        {
            std::cout << "Reconnecting.\n";
            e.restart();
        }else if(input == "force_dc")
        {
            nlohmann::json json;
            json["op"] = 2;
            e.getWebsocketHandler().getConnection()->sendPayload(json);
        }else if(input == "fakekill")
        {
            //not working yet lol segfaults next run because it cant parse resumed events from a new bot state
            nlohmann::json json;
            json["op"] = 2;
            e.getWebsocketHandler().getConnection()->sendPayload(json);
            e.shutdown();
            break;
        }
        
    }
    //run.join();

    return 0;
}