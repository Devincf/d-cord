#include "bot.hpp"

#include "dppcord/command/parser/CommandParser.hpp"

int main(int argc, char* argv[])
{
    std::ifstream t("token.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    //std::cout << str << "\n";

    dppcord::Command* cmd = dppcord::CommandParser::parse("!test hello true 3001 false 3.01");
    std::cout << cmd->get() << '\n';

    delete cmd;

    //Example e(str);
    return 0;
}