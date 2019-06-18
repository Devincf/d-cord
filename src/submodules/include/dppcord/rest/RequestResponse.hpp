/**
 * @file RequestResponse.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:51
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef REQUESTRESPONSE_HPP
#define REQUESTRESPONSE_HPP

#include <string>

namespace dppcord
{
class RequestResponse
{
public:
    RequestResponse();
    RequestResponse(const std::string& responseStr);
    ~RequestResponse();

    const std::string& get() const;

private:
    std::string m_responseString;
};
} // namespace dppcord

#endif