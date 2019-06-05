/**
 * @file plugin.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-04 06:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "plugin.hpp"
#include <iostream>

#include "dppcord/core/client/DiscordClient.hpp"
#include "dppcord/command/builder/CommandMap.hpp"

#include "dppcord/core/handler/UsersHandler.hpp"

#include "dppcord/core/objects/message/BaseMessage.hpp"
#include "dppcord/core/objects/channel/BaseChannel.hpp"
#include "dppcord/core/objects/guild/Guild.hpp"

#include "dppcord/util/jsonutil.hpp"
#include "dppcord/util/emojilist.hpp"

namespace dppcord::plugins::moneysystem
{

MoneySystem::MoneySystem(DiscordClient *pClient) : IPlugin(pClient, "Example Plugin")
{
    std::cout << "MoneySystem loaded\n";
    m_globalMoneyMap = MoneyMap();
    m_guildMoneyMap = {};
}
MoneySystem::~MoneySystem() {}

void MoneySystem::init()
{
    std::cout << "money init\n";
    CommandMap::addCommand("!leaderboard",
                           [=](const BaseMessage &msg, const ArgumentList &argList) {
                               //auto leaderboard = Singleton<MoneyManager>::get()->getLeaderboard(10);
                               auto leaderboard = m_pClient->getDatabase().query("SELECT id,money FROM users ORDER BY money DESC LIMIT 10");
                               std::stringstream ss;
                               int incrementer = 1;
                               for (auto i : leaderboard)
                               {
                                   //auto userptr = Singleton<UserManager>::get()->findUser(current.first);
                                    auto userptr = m_pClient->getUsersHandler().findUser(i["id"]);
                                    ss << emoji::rankingEmojis.at(incrementer++) << " **" << userptr.getName() << "**      ( " << i["money"] << " )\n\n";
                               }
                               nlohmann::json json;
                               //https://news.bitcoin.com/wp-content/uploads/2018/07/ranking-300x237.jpg

                               nlohmann::json embed;
                               embed["title"] = ":trophy:  Rankings";
                               embed["description"] = ss.str();
                               embed["thumbnail"]["url"] = "https://news.bitcoin.com/wp-content/uploads/2018/07/ranking-300x237.jpg";
                               embed["color"] = 8388352;

                               json["embed"] = embed;

                               msg.channel().sendMessageExtended(json);
                           });

    m_pClient->getWebsocketHandler().getDispatcher().getEvent("MESSAGE_CREATE")->bind([&](const nlohmann::json &json) {
        //std::cout << json.dump(2) << '\n';
        if (tryGetSnowflake("guild_id", json) != 439065048628068363 || tryGetSnowflake("id", json["author"]) == 444648378199048214) // Todo: remove first part later(keep bot msg check)
            return;
        if (++m_messagesSinceDrop >= messagesUntilDrop)
        {
            //drop()
            Guild& guild = m_pClient->getGuildsHandler().getGuild(tryGetSnowflake("guild_id", json));
            std::cout << guild.getName() << '\n';
            auto& msg = guild.getMessage(tryGetSnowflake("id", json));
            nlohmann::json drop_json;
            nlohmann::json embed;
            embed["title"] = "       Coin drop";
            embed["color"] = 10824234;
            embed["description"] = "w-would u like a drink master?";
            embed["image"]["url"] = "https://cdn.discordapp.com/attachments/439065048628068365/576535445123629064/20190510_172533.jpg";
            drop_json["embed"] = embed;
            auto& dropMessage = msg.channel().sendMessageExtended(drop_json);
            dropMessage.react(emoji::coffee);
            dropMessage.reactionListener(
                [=](BaseMessage &msg, const nlohmann::json &json) {
                    auto userptr = m_pClient->getUsersHandler().findUser(tryGetSnowflake("user_id", json));
                    if (tryGetJson<std::string>("name", json["emoji"]) == emoji::coffee && userptr.getId() != m_pClient->getBotUser().getId())
                    {
                        //claim money.
                        //std::cout << json.dump(2) << '\n';
                        //Todo: think about whether I want to localize this or not
                        //m_globalMoneyMap.find(tryGetSnowflake("user_id", json))->second += 100; //Todo: replace with configurable moneyvalue
                        //updata data in database
                        m_pClient->getDatabase().query("UPDATE users SET money=money+100 WHERE id=" + std::to_string(userptr.getId()));
                        msg.remove();
                        msg.channel().sendMessage(userptr.getName() + " claimed 100 coins!");
                    }
                });
            m_messagesSinceDrop = 0;
        }
    });

    //load monies from database.
}
void MoneySystem::shutdown() {}

const MoneyMap &MoneySystem::getGlobalMoneyMap() const { return m_globalMoneyMap; }

} // namespace dppcord::plugins::moneysystem