/**
 * @file DecimalArgument.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 03:20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DECIMALARGUMENT_HPP
#define DECIMALARGUMENT_HPP

#include "Argument.hpp"
namespace dppcord
{
class DecimalArgument : public Argument<double>
{
    using Argument::Argument;

public:
    DecimalArgument();
    virtual ~DecimalArgument();
    
    std::string str() override;
    DecimalArgument(const char* str);
};
} // namespace dppcord

#endif