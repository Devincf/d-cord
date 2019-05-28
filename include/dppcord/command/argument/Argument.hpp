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

#include "IArgument.hpp"

namespace dppcord
{
template <typename T>
class Argument : public IArgument
{
    public:
    Argument(const T& arg)
    {
        m_val = arg;
    }
    Argument(){}
    virtual ~Argument(){}

    T get(){ return m_val;}

    Argument& operator=(const T& rhs)
    {
        m_val = rhs;
        return *this;
    }
    virtual std::string str()
    {
        return "argument()";
    };
    protected:
    T m_val;
};
} // namespace dppcord

#endif