#include <string>
#include <fstream>
#include <streambuf>

#include "dppcord/client/DiscordClient.hpp"


class Example : public dppcord::DiscordClient
{
    using dppcord::DiscordClient::DiscordClient;
};