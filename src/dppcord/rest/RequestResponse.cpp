/**
 * @file RequestResponse.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 03:52
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dppcord/rest/RequestResponse.hpp"

namespace dppcord
{
RequestResponse::RequestResponse() {}
RequestResponse::RequestResponse(const std::string &responseStr) : m_responseString(responseStr)
{
}
RequestResponse::~RequestResponse() {}
} // namespace dppcord