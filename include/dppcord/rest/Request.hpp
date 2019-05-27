/**
 * @file Request.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "RequestHeaderList.hpp"
#include "RequestContent.hpp"
#include "RequestResponse.hpp"

namespace dppcord
{
    class Request
    {
        public:
        static RequestResponse sendGET(const std::string& url, const RequestHeaderList& headerList, const RequestContent& content);

    };
}


#endif