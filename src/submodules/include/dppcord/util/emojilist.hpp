/**
 * @file EmojiList.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-05 01:51
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EMOJILIST_HPP
#define EMOJILIST_HPP

#include <string>

namespace dppcord::emoji
{
    static const std::string pizza = "🍕";
    static const std::string key = "🔑";
    static const std::string coffee = "☕";

    const std::map<int, std::string> rankingEmojis = {{1,":one:"},{2,":two:"},{3,":three:"},{4,":four:"},{5,":five:"},{6,":six:"},{7,":seven:"},{8,":eight:"},{9,":nine:"}, {10,":keycap_ten:"}};

}

#endif