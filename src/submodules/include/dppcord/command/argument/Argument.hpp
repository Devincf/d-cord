/**
 * @file Argument.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-27 09:48
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <any>
#include <iostream>

namespace dppcord
{

class Argument
{
    public:
    ~Argument() = default;
    Argument()
    {

    }

    template <typename T>
    Argument(T arg) : m_value(arg){}

    Argument(const Argument& arg)
    {
        m_value = arg.getAny();
    }
    Argument& operator=(const Argument& rhs)
    {
        m_value = rhs.getAny();
        return *this;
    }

    std::any getAny() const
    {
        return m_value;
    }

    template <typename T>
    T as()const 
    {
        try
        {
            T ret = std::any_cast<T>(m_value);
            return ret;
        }
        catch(const std::exception& e)
        {
            std::cout << "Error while casting Argument!\n";
            return T();
        }
    }

    std::string get() const 
    {
        return std::any_cast<std::string>(m_value);
    }

    private:
    std::any m_value;
};
} // namespace dppcord

#endif