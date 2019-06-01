#include "bot.hpp"

#include "dppcord/command/builder/CommandBuilder.hpp"
#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"

int main(int argc, char* argv[])
{
    std::ifstream t("token.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

    dppcord::CommandMap::addCommand("!test",[](dppcord::BaseMessage* msg, const dppcord::ArgumentList& args)
    {
        for(auto arg : args.getArguments())
        {
            std::cout << arg.get() << '\n';
        }
        msg->channel()->sendMessage("Hello World!");
    });

    //dppcord::CommandBuilder::tryBuild("!test hello true 3001 false 3.01");
    //std::cout << cmd->get() << '\n';


    Example e(str);
    return 0;
}