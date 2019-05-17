#include "bot.hpp"

int main(int argc, char* argv[])
{
    std::ifstream t("token.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    std::cout << str << "\n";
    Example e(str);
    return 0;
}