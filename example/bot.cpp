#include "bot.hpp"

#include <string>
#include <fstream>
#include <streambuf>

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"
#include "dppcord/core/objects/channel/TextChannel.hpp"

#include "plugins/example_plugin/plugin.hpp"
#include "plugins/MoneySystem/plugin.hpp"

#include "dppcord/rest/DiscordEndpoint.hpp"

#include "nlohmann/json.hpp"

#include "dppcord/util/emojilist.hpp"

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
        TextChannel& channel = dynamic_cast<TextChannel&>(msg.channel());
        channel.sendMessage("pong").reactionListener(
            [&channel](dppcord::BaseMessage &msg, const nlohmann::json &json) {
                std::cout << msg.content() << '\n';
                channel.sendMessage("reacted to pong!");
            });
    });

    e.loadPlugin<ExamplePlugin>();
    e.loadPlugin<dppcord::plugins::moneysystem::MoneySystem>();

    /* 
    std::string g = "439065048628068363";
    std::string c = "445942826534961153";
    auto test = DiscordEndpoint::getGuild("439065048628068363");
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
    std::cout << DiscordEndpoint::createGuildIntegration(g, "twitch", "1");//change to int
    std::cout << DiscordEndpoint::modifyGuildIntegration(g, , {{"expire_grace_period", 1337}});
    std::cout << DiscordEndpoint::deleteGuildIntegration(g,);
    std::cout << DiscordEndpoint::modifyGuildEmbed(g, {{"enabled", true}, {"channel_id", "445942826534961153"}});
    std::cout << DiscordEndpoint::beginGuildPrune(g, 2, true);
    std::cout << DiscordEndpoint::deleteGuildRole(g, "588336104055242753");
    std::cout << DiscordEndpoint::modifyGuildRole(g, "588336851081887745", {{"name", "Modified name"}});
    std::cout << DiscordEndpoint::createGuildRole(g, {{"name", "test role"}}).dump(4) << '\n';
    std::cout << DiscordEndpoint::getGuildRoles(g).dump(4) << '\n';
    nlohmann::json groleposjson = nlohmann::json::array();
    groleposjson.push_back({{"id", "588338590208098314"},{ "position", 2}});
    groleposjson.push_back({{"id", "576209601482063875"},{ "position", 1}});
    std::cout << DiscordEndpoint::modifyGuildRolePositions(g, groleposjson);
    std::cout << DiscordEndpoint::getChannel(c) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::modifyChannel(c, {{"name", "hmmm3"}}) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deleteChannel("588599803525464065") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getChannelMessages(c) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getChannelMessage(c, "588077844358365194") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deleteOwnReaction(c,"588077501348184083", dppcord::emoji::coffee) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deleteUserReaction(c, "588077501348184083", dppcord::emoji::coffee,"142733073262444545") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getReactions(c,"588077833738518555", dppcord::emoji::coffee) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deleteAllReactions(c,"588077833738518555") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::editMessage(c,"588077844358365194", {{"content", "edited"}}) << '\n';
    std::cout << "###############################################\n\n\n";
    nlohmann::json arr = nlohmann::json::array();
    arr.push_back("588077832467513367");
    arr.push_back("588077833738518555");
    nlohmann::json obj = {{"messages", arr}};
    std::cout << obj.dump(4);
    std::cout << DiscordEndpoint::bulkDeleteMessages(c, {{"messages", arr}}) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getChannelInvites(c) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::createChannelInvite(c,{{}}) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::triggerTypingIndicator(c) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getPinnedMessages(c) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::addPinnedChannelMessage(c,"588076479028658177") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deletePinnedChannelMessage(c,"588075799668850689") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::listGuildEmojis(g).dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildEmoji(g, "546316631023026176").dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    //std::cout << DiscordEndpoint::createGuildEmoji(g) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::modifyGuildEmoji(g, "546316631023026176",{{"name", "emoji2"}}) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::deleteEmoji(g,"588609329720983562") << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getCurrentUser().dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getUser("142733073262444545").dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getCurrentUserGuilds().dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::modifyCurrentUser({{"username", "Lumi Bot"}}).dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getUserDMs().dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getUserConnections().dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getChannelWebhooks(c).dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getGuildWebhooks(g).dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getWebhook("576458939202273291").dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
    std::cout << DiscordEndpoint::getWebhookWithToken("576458939202273291","COdDKrRI6j1c6t2mVPWRO9ortC60uLn0FXjR9OcFhHldTJLZYmUkoDa2g5rGN0kTUxfR").dump(4) << '\n';
    std::cout << "###############################################\n\n\n";
     */



    
    
    std::thread run(&Example::run, &e);
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
    run.join();

    return 0;
}