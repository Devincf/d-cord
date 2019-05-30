/**
 * @file ArgumentConversion.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:44
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ARGUMENTCONVERSION_HPP
#define ARGUMENTCONVERSION_HPP

#include <memory>

#include "dppcord/command/argument/BoolArgument.hpp"
#include "dppcord/command/argument/StringArgument.hpp"
#include "dppcord/command/argument/DecimalArgument.hpp"

namespace dppcord
{


    
template <typename S>
S convert2(std::shared_ptr<IArgument> arg)
{
    return std::dynamic_pointer_cast<Argument<S>>(arg)->get();
}

} // namespace dppcord

#endif