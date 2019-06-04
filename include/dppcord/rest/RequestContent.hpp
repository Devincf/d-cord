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

#include "rapidjson/document.h"

namespace dppcord
{
class RequestContent
{
public:
    RequestContent();
    ~RequestContent();
    RequestContent(const rapidjson::Document& content);
    int size() const;
    std::string get() const;
private:
    Document m_content;
};
} // namespace dppcord

#endif