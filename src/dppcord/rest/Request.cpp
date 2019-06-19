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
const RequestResponse Request::sendPOST(const std::string &url, const RequestHeaderList &headerList, const RequestContent &content)
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
        myRequest.setOpt<PostFieldSize>(content.get().size());
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
const RequestResponse Request::sendGET(std::string url, const RequestHeaderList &headerList, const RequestContent &content)
{
    try
    {
        curlpp::Cleanup myCleanup;
        std::stringstream ss;

        std::stringstream finalurl;
        finalurl << url;
        if (content.size() > 0)
        {
            finalurl << '?';
            const auto json = content.raw();
            for (auto it = json.begin(); it != json.end(); ++it)
            {
                finalurl << it.key() << '=' << it.value() << '&';
            }
        }
        // Our request to be sent.
        curlpp::Easy myRequest;
        myRequest.setOpt<Url>(finalurl.str());
        myRequest.setOpt<HttpHeader>(headerList.get());
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

const RequestResponse Request::sendDELETE(const std::string &url, const RequestHeaderList &headerList, const RequestContent &content)
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

const RequestResponse Request::sendPATCH(const std::string &url, const RequestHeaderList &headerList, const RequestContent &content)
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
        myRequest.setOpt<CustomRequest>("PATCH");
        myRequest.setOpt<WriteStream>(&ss);

        // Send request and get a result.
        myRequest.perform();
        return RequestResponse{ss.str()};
    }
    catch (const std::exception &e)
    {
        std::cerr << "Request::sendPUT(): " << e.what() << '\n';
    }
    return RequestResponse("");
}

const RequestResponse Request::sendPUT(const std::string &url, const RequestHeaderList &headerList, const RequestContent &content)
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
        std::cerr << "Request::sendPUT(): " << e.what() << '\n';
    }
    return RequestResponse("");
}

} // namespace dppcord