/**
 * @file IIdentifiableObject.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-26 09:08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef IIDENTIFIABLEOBJECT_HPP
#define IIDENTIFIABLEOBJECT_HPP

#include "Snowflake.hpp"

namespace dppcord
{
    class IIdentifiableObject
    {
        public:
        Snowflake getId(){ return m_id; }
        void setId(const Snowflake& id){m_id = id;}
        protected:
        Snowflake m_id;
        private:
    };
}

#endif