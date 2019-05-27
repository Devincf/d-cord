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
    /**
     * @brief Returns the name of the object
     * @return std::string 
     */
    std::string getName() { return m_name; }
    /**
     * @brief Sets the name of the object
     * 
     * @param name 
     */
    void setName(const std::string &name) { m_name = name; }

protected:
    /**
     * @brief The name of the object
     */
    std::string m_name;
};
} // namespace dppcord

#endif