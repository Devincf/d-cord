/**
 * @file RequestHeaderList.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:35
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef REQUESTHEADERLIST_HPP
#define REQUESTHEADERLIST_HPP

#include <list>
#include <string>

namespace dppcord
{
    enum RequestContentType{
        REQUESTCONTENT_MULTIPART_FORMDATA,
        REQUESTCONTENT_APPLICATION_JSON
    };

    class RequestHeaderList
    {
        public:
        RequestHeaderList();
        RequestHeaderList(const std::string&& auth, RequestContentType&& rct);
        RequestHeaderList(const std::string& auth, RequestContentType&& rct);
        RequestHeaderList(RequestContentType&& rct);
        RequestHeaderList(std::string& auth);

        RequestHeaderList& addHeader(const std::string& header);
        const std::list<std::string>& get() const;
        RequestHeaderList& setContent(RequestContentType&& rct);
        private:
        std::list<std::string> m_headers;
    };
}

#endif