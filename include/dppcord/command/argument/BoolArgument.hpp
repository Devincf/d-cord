/**
 * @file BoolArgument.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-28 03:09
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef BOOLARGUMENT_HPP
#define BOOLARGUMENT_HPP

#include "Argument.hpp"
namespace dppcord
{
class BoolArgument : public Argument<bool>
{
    using Argument::Argument;

public:
    BoolArgument();
    virtual ~BoolArgument();
    std::string str() override;
};
} // namespace dppcord

#endif