/**
 * @file Emoji.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 09:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/emoji/Emoji.hpp"
#include "dppcord/core/objects/user/GuildUser.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
Emoji::Emoji() {}
Emoji::~Emoji() {}

Emoji::Emoji(const nlohmann::json& emojijson): Emoji(nullptr, emojijson){}

Emoji::Emoji(std::shared_ptr<User> pUser, const nlohmann::json &emojijson): m_user(pUser)
{
    m_id = tryGetSnowflake("id", emojijson);
    m_name = tryGetJson<std::string>("name", emojijson);
    //user
    m_requiredColons = tryGetJson<bool>("require_colons", emojijson);
    m_managed = tryGetJson<bool>("managed", emojijson);
    m_animated = tryGetJson<bool>("animated", emojijson);

    if(m_user)
        std::cout << m_name << " creator:  " << m_user->getName() <<'\n';
}
} // namespace dppcord