/**
 * @file IArgument.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 02:33
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef IARGUMENT_HPP
#define IARGUMENT_HPP

#include <string>

namespace dppcord
{
    class IArgument
    {
        public:
        IArgument() = default;
        virtual ~IArgument()= default;
        virtual std::string str() = 0;
    };
}

#endif