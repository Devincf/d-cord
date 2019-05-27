/**
 * @file RequestHeaderList.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/rest/RequestHeaderList.hpp"

namespace dppcord
{
RequestHeaderList &RequestHeaderList::addHeader(const std::string &header)
{
    m_headers.push_back(header);
    return *this;
}

std::list<std::string> RequestHeaderList::get() const
{
    return m_headers;
}

RequestHeaderList &RequestHeaderList::setContent(RequestContentType rct)
{
    switch (rct)
    {
    case REQUESTCONTENT_MULTIPART_FORMDATA:
        m_headers.push_back("Content-Type: multipart/form-data");
        break;
    default:
        break;
    }
    return *this;
}
} // namespace dppcord