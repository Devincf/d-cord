/**
 * @file RequestContent.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef REQUESTCONTENT_HPP
#define REQUESTCONTENT_HPP

#include "nlohmann/json.hpp"

namespace dppcord
{
class RequestContent
{
public:
    RequestContent();
    ~RequestContent();
    RequestContent(const nlohmann::json& content);
    const int size() const;
    const std::string get() const;
    const nlohmann::json raw() const;
private:
    nlohmann::json m_content;
};
} // namespace dppcord

#endif