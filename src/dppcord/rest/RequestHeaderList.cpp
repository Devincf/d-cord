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

RequestHeaderList::RequestHeaderList() {}

RequestHeaderList::RequestHeaderList(const std::string &&auth, RequestContentType &&rct)
{
    setContent(std::forward<RequestContentType>(rct));
    m_headers.push_back("Authorization: Bot " + auth);
}
RequestHeaderList::RequestHeaderList(const std::string &auth, RequestContentType &&rct)
{
    setContent(std::forward<RequestContentType>(rct));
    m_headers.push_back("Authorization: Bot " + auth);
}
RequestHeaderList::RequestHeaderList(RequestContentType &&rct)
{
    setContent(std::forward<RequestContentType>(rct));
}
RequestHeaderList::RequestHeaderList(std::string &auth)
{
    m_headers.push_back("Authorization: Bot " + auth);
}

RequestHeaderList &RequestHeaderList::addHeader(const std::string &header)
{
    m_headers.push_back(header);
    return *this;
}

const std::list<std::string> &RequestHeaderList::get() const
{
    return m_headers;
}

RequestHeaderList &RequestHeaderList::setContent(RequestContentType&& rct)
{
    switch (rct)
    {
    case REQUESTCONTENT_MULTIPART_FORMDATA:
        m_headers.push_back("Content-Type: multipart/form-data");
        break;
    case REQUESTCONTENT_APPLICATION_JSON:
        m_headers.push_back("Content-Type: application/json");
        break;
    default:
        break;
    }
    return *this;
}
} // namespace dppcord