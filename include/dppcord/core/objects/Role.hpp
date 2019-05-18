/**
 * @file Role.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 09:02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ROLE_HPP
#define ROLE_HPP

#include "Snowflake.hpp"

namespace dppcord
{
class Role
{
public:
    Role(const nlohmann::json &rolejson);

    ~Role();
private:
    Role();
    /**
     * @brief Role id
     */
    Snowflake m_id;
    /**
     * @brief Role name
     */
    std::string m_name;
    /**
     * @brief Integer representation of hexadecimal color code
     */
    int m_color;
    /**
     * @brief If this role is pinned in the user listing
     */
    bool m_hoist;
    /**
     * @brief position of this role
     */
    int m_position;
    /**
     * @brief Permission bit set
     */
    int m_permissions;
    /**
     * @brief Whether this role is managed by an integration
     */
    bool m_managed;
    /**
     * @brief Whether this role is mentionable or not
     */
    bool m_mentionable;
};
} // namespace dppcord

#endif