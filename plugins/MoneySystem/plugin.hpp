/**
 * @file plugin.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-04 06:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/plugin/IPlugin.hpp"

#include "dppcord/core/objects/Snowflake.hpp"

namespace dppcord::plugins::moneysystem
{

const static int messagesUntilDrop = 10;

typedef std::map<Snowflake, int> MoneyMap;

class MoneySystem : public IPlugin
{
public:
    MoneySystem(DiscordClient *pClient);
    ~MoneySystem();

    void init()override;
    void shutdown()override;

    const MoneyMap& getGlobalMoneyMap() const; 

    private:
    MoneyMap m_globalMoneyMap;
    std::map<Snowflake, MoneyMap> m_guildMoneyMap;

    int m_messagesSinceDrop;
};
} // namespace dppcord::moneysystem