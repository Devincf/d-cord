/**
 * @file LambdaCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:23
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LAMBDACOMMAND_HPP
#define LAMBDACOMMAND_HPP

#include "Command.hpp"
#include <functional>
#include "unpack/Unpack.hpp"

namespace dppcord
{
template <typename... Args>
class LambdaCommand : public Command
{
public:
    LambdaCommand()=default;
    LambdaCommand(std::function<void(Args...)> f) : fn(f) {}
    ~LambdaCommand() = default;

    void internal_proc(const std::vector<std::shared_ptr<IArgument>> &vec)
    {
        unpack_arguments<sizeof...(Args)>(fn, vec);
    }

    int getArgumentCount()
    {
        return sizeof...(Args);
    }

    std::function<void(Args...)> fn;
};
} // namespace dppcord

#endif