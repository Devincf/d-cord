/**
 * @file Request.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:42
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/rest/Request.hpp"

#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace curlpp::options;

namespace dppcord
{
RequestResponse Request::sendPOST(const std::string &url, const RequestHeaderList &headerList, const RequestContent &content)
{
    try
    {
        curlpp::Cleanup myCleanup;
        std::stringstream ss;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(url);
        myRequest.setOpt<HttpHeader>(headerList.get());
        myRequest.setOpt<PostFields>(content.get());
        myRequest.setOpt<PostFieldSize>(content.size());
        myRequest.setOpt<WriteStream>(&ss);

        // Send request and get a result.
        myRequest.perform();
        return RequestResponse{ss.str()};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return RequestResponse("");
}

RequestResponse Request::sendDELETE(const std::string &url, const RequestHeaderList &headerList)
{
    try
    {
        curlpp::Cleanup myCleanup;
        std::stringstream ss;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(url);
        myRequest.setOpt<HttpHeader>(headerList.get());
        myRequest.setOpt<CustomRequest>("DELETE");
        myRequest.setOpt<WriteStream>(&ss);

        // Send request and get a result.
        myRequest.perform();
        return RequestResponse{ss.str()};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return RequestResponse("");
}

RequestResponse Request::sendPUT(const std::string& url, const RequestHeaderList& headerList)
{
    try
    {
        curlpp::Cleanup myCleanup;
        std::stringstream ss;

        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(url);
        myRequest.setOpt<HttpHeader>(headerList.get());
        myRequest.setOpt<CustomRequest>("PUT");
        myRequest.setOpt<WriteStream>(&ss);

        // Send request and get a result.
        myRequest.perform();
        return RequestResponse{ss.str()};
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return RequestResponse("");
}

} // namespace dppcord