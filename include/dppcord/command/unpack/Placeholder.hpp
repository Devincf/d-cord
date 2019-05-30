/**
 * @file Placeholder.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:50
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef PLACEHOLDER_HPP
#define PLACEHOLDER_HPP

#include <type_traits>
#include <functional>

template<int> // begin with 0 here!
struct placeholder_template
{};


namespace std
{
    template<int N>
    struct is_placeholder< placeholder_template<N> >
        : integral_constant<int, N+1> // the one is important
    {};
}

#endif