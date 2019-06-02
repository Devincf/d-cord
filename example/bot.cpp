#include "bot.hpp"

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"

#include "plugins/example_plugin/plugin.hpp"

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
            [](dppcord::BaseMessage *msg, const nlohmann::json &json) {
                std::cout << msg->content() << '\n';
                msg->channel()->sendMessage("reacted to pong!");
            });
    });

    //dppcord::CommandBuilder::tryBuild("!test hello true 3001 false 3.01");
    //std::cout << cmd->get() << '\n';

    e.loadPlugin<ExamplePlugin>();
    e.run();
    return 0;
}