/**
 * @file Emoji.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-18 09:12
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EMOJI_HPP
#define EMOJI_HPP
#include "Snowflake.hpp"

namespace dppcord
{
class User;
/**
     * @brief 
     * Todo: add roles
     */
class Emoji
{
    public:
    Emoji(const nlohmann::json& emojijson);
    ~Emoji();
    private:
    Emoji();
    /**
     * @brief Emoji id 
     */
    Snowflake m_id;
    /**
     * @brief Emoji name
     */
    std::string m_name;
    /**
     * @brief Creator of the emoji
     * Todo: implement
     */
    //User *m_user;
    /**
     * @brief Whether the emoji needs to be wrapped in colons or not
     */
    bool m_requiredColons;
    /**
     * @brief Whether this emoji is managed or not
     */
    bool m_managed;
    /**
     * @brief Whether this emoji is animated or not
     */
    bool m_animated;
};
} // namespace dppcord

#endif