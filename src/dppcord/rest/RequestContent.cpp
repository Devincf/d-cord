/**
 * @file RequestContent.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/rest/RequestContent.hpp"

namespace dppcord
{

RequestContent::RequestContent() {}
RequestContent::~RequestContent() {}
RequestContent::RequestContent(const nlohmann::json &content):m_content(content)
{
}

std::string RequestContent::get() const
{
    return m_content.dump();
}

int RequestContent::size() const
{
    return m_content.dump().size();
}
} // namespace dppcord