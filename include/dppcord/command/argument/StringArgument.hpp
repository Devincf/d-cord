/**
 * @file StringArgument.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 09:49
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef STRINGARGUMENT_HPP
#define STRINGARGUMENT_HPP

#include "Argument.hpp"
namespace dppcord
{
class StringArgument : public Argument<std::string>
{
    using Argument::Argument;

public:
    StringArgument();
    StringArgument(const char* str);
    virtual ~StringArgument();

    StringArgument &operator=(const char *rhs);
    
    std::string str() override;

};
} // namespace dppcord

#endif