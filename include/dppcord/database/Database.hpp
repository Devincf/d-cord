/**
 * @file Database.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 11:53
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP
#include <string>
#include <map>
#include <vector>
namespace dppcord
{
typedef std::map<std::string, std::string> QueryRow;
typedef std::vector<QueryRow> QueryResult;

class Database
{
public:
    virtual ~Database();
    virtual QueryResult query(const std::string &queryStr);
};

} // namespace dppcord

#endif