/**
 * @file config.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-06 05:36
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CONSTANTCONFIG_HPP
#define CONSTANTCONFIG_HPP

#include "nlohmann/json.hpp"

namespace dppcord::config
{
    const nlohmann::json main = {
        {"botname",     "unnamed bot"},
        {"botdesc",     "a basic unnamed bot written using d++cord"},
        {"botver",      "1.0"}
    };
}

#endif