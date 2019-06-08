#include "bot.hpp"

#include <string>
#include <fstream>
#include <streambuf>

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"

#include "plugins/example_plugin/plugin.hpp"
#include "plugins/MoneySystem/plugin.hpp"

#include "nlohmann/json.hpp"

int main(int argc, char *argv[])
{
    std::ifstream t("token.txt");
    std::string token((std::istreambuf_iterator<char>(t)),
                      std::istreambuf_iterator<char>());

    Example e(token);

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