/**
 * @file INamedObject.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 09:16
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef INAMEDOBJECT_HPP
#define INAMEDOBJECT_HPP

#include <string>

namespace dppcord
{
    class INamedObject
    {
        public:
        std::string getName(){return m_name; }
        void setName(const std::string& name){m_name = name;}
        protected:
        std::string m_name;
    };
}

#endif