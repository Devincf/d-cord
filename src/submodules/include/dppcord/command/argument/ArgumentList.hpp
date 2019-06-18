/**
 * @file ArgumentList.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-01 02:34
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef ARGUMENTLIST_HPP
#define ARGUMENTLIST_HPP
#include <vector>

#include "Argument.hpp"

namespace dppcord
{
class ArgumentList
{
public:

    std::vector<Argument> getArguments() const;
    void addArgument(const Argument &any);

    const Argument &operator[](int index) const;

private:
    std::vector<Argument> m_arguments;
};
} // namespace dppcord

#endif