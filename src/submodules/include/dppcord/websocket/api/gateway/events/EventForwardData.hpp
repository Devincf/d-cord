/**
 * @file EventForwardData.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-08 03:43
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EVENTFORWARDDATA_HPP
#define EVENTFORWARDDATA_HPP

#include <any>
#include <iostream>


namespace dppcord
{

template <typename T>
const T& fromAny(const std::any &any)
{
    if (any.has_value())
    {
        return *(std::any_cast<const T*>(any));
    }
    else
    {
        throw std::runtime_error("Forward data has not been set!");
    }
}

template <int N>
class EventForwardData
{
    public:
    template <typename T>
    void add(const T &&rhs)
    {
        data[current++] = &rhs;
    }
    template <typename T>
    void add(const T &rhs)
    {
        data[current++] = &rhs;
    }
    const std::any &next()
    {
        return data.at(--current);
    }
    void reset()
    {
        current = 0;
    }
    void prepare()
    {
        current = N;
    }
    private:
    std::array<std::any, N> data;
    int current = 0;
};
} // namespace dppcord

#endif