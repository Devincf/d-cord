#include "dppcord/client/DiscordClient.hpp"


class Example : public dppcord::DiscordClient
{
    public:
    Example(const std::string& token):dppcord::DiscordClient(token)
    {

    }
};

int main()
{
    std::ifstream t("token.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());

    Example e;
    return 0;
}