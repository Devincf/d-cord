/**
 * @file Role.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 09:11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/core/objects/Role.hpp"
#include "dppcord/util/jsonutil.hpp"

namespace dppcord
{
    Role::Role(){}
    Role::~Role(){}

    Role::Role(const nlohmann::json& rolejson)
    {
        m_id = tryGetSnowflake("id",rolejson);
        m_name =tryGetJson<std::string>("name",rolejson);
        m_color = tryGetJson<int>("color",rolejson);
        m_hoist = tryGetJson<bool>("hoist",rolejson);
        m_position = tryGetJson<int>("position",rolejson);
        m_permissions = tryGetJson<int>("permissions",rolejson);
        m_managed = tryGetJson<bool>("managed",rolejson);
        m_mentionable = tryGetJson<bool>("mentionable",rolejson);
    }

    std::string Role::getName(){ return m_name;}
}