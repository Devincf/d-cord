/**
 * @file WrappedCommand.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-29 10:31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef WRAPPEDCOMMAND_HPP
#define WRAPPEDCOMMAND_HPP

#include "Command.hpp"
#include "unpack/Placeholder.hpp"

namespace dppcord
{
template <typename... Args>
class WrappedCommand : public Command
{
public:
    WrappedCommand() = default;
    virtual ~WrappedCommand() = default;

    virtual void proc(Args... args) = 0;

    template <std::size_t... Is>
    void internal_proc(const std::vector<std::shared_ptr<IArgument>> &vec, std::index_sequence<Is...> seq)
    {
        std::function<void(Args...)> x = std::bind(&WrappedCommand::proc, this, placeholder_template<Is>{}...);
        unpack_arguments<sizeof...(Args)>(x, vec);
    }

    void internal_proc(const std::vector<std::shared_ptr<IArgument>> &vec)
    {
        internal_proc(vec, std::make_index_sequence<sizeof...(Args)>{});
    }
};
} // namespace dppcord

#endif