/**
 * @file Unpack.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:41
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef UNPACK_HPP
#define UNPACK_HPP

#include "ArgumentConversion.hpp"

namespace dppcord
{

template <typename... Args, typename... Foo>
void test2(std::function<void(Args...)> fn, Foo... foos)
{
    (void)std::initializer_list<int>{(fn(convert2<Args>(foos)...), 0)};
}

template <std::size_t... S, typename... Args>
void unpack_arguments(std::function<void(Args...)> fn, const std::vector<std::shared_ptr<IArgument>> &vec, std::index_sequence<S...>)
{
    test2(fn, vec[S]...);
}

template <std::size_t size, typename... Args>
void unpack_arguments(std::function<void(Args...)> fn, const std::vector<std::shared_ptr<IArgument>> &vec)
{
    if (vec.size() != size)
        throw /* choose your error */;
    unpack_arguments(fn, vec, std::make_index_sequence<size>());
}

template <std::size_t size, typename F>
void unpack_arguments(F fn, const std::vector<std::shared_ptr<IArgument>> &vec)
{
    if (vec.size() != size)
        throw /* choose your error */;
    unpack_arguments(std::function(fn), vec, std::make_index_sequence<size>());
}

} // namespace dppcord

#endif