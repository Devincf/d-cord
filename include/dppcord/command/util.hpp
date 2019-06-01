/**
 * @file util.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-01 02:48
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef FNUTIL_HPP
#define FNUTIL_HPP

#include <functional>

namespace dppcord
{
class BaseMessage;
class ArgumentList;
using callback = std::function<void(BaseMessage*, const ArgumentList&)>;
}

#endif