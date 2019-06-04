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

#include "IIdentifiableObject.hpp"
#include "dppcord/core/objects/INamedObject.hpp"

namespace dppcord
{
class Guild;
class Role: public IIdentifiableObject, public INamedObject
{
public:
    /**
     * @brief Construct a new Role object with given json data 
     * @param json data to construct the role object with
     */
    Role(Guild* pGuild,const Document &rolejson);
    /**
     * @brief Destroy the Role object
     */
    ~Role();

private:
    /**
     * @brief Construct a new Role object
     */
    Role();
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
    /**
     * @brief Pointer to the guild this role belongs to
     */
    Guild* m_guild;
};
} // namespace dppcord

#endif