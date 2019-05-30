#include "bot.hpp"

#include "dppcord/command/builder/CommandBuilder.hpp"

int main(int argc, char* argv[])
{
    std::ifstream t("token.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    //std::cout << str << "\n";

    //auto cmd = dppcord::CommandParser::parse("!test hello true 3001 false 3.01");
    std::function<void(std::string, bool, double, bool, double)> fn = [](std::string a, bool b, double c, bool d, double e){ 
        std::cout << a << "##" << b << "##" <<  c << "##" << d << "##" << e <<'\n';
        };
    dppcord::CommandMap::addCommand("!test",fn);

    //dppcord::CommandBuilder::tryBuild("!test hello true 3001 false 3.01");
    dppcord::CommandBuilder::tryBuildCommand("!test hello true 3001 false 3.01");
    //std::cout << cmd->get() << '\n';


    //Example e(str);
    return 0;
}