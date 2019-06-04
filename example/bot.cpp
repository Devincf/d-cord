#include "bot.hpp"

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"

#include "plugins/example_plugin/plugin.hpp"

#include "rapidjson/document.h"
using rapidjson::Document&;

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

    dppcord::CommandMap::addCommand("!ping", [](dppcord::BaseMessage *msg, const dppcord::ArgumentList &args) {
        msg->channel()->sendMessage("pong")->reactionListener(
            [](dppcord::BaseMessage *msg, const Document &json) {
                std::cout << msg->content() << '\n';
                msg->channel()->sendMessage("reacted to pong!");
            });
    });

    e.loadPlugin<ExamplePlugin>();
    std::thread run(&Example::run, &e);
    std::string input;
    for(;;)
    {
        std::cin >> input;
        if(input == "exit")
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
            Document json;
            json["op"] = 2;
            e.getWebsocketHandler()->getConnection()->sendPayload(json);
        }
    }
    run.join();

    return 0;
}