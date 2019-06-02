/**
 * @file SQLiteDatabase.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 11:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SQLITEDATABASE_HPP
#define SQLITEDATABASE_HPP
#include <memory>
#include <sqlite3.h>

#include "Database.hpp"

namespace dppcord
{


struct SQLiteWrapper
{
    SQLiteWrapper() = default;
    ~SQLiteWrapper()
    {
        sqlite3_close(db);
    }
    sqlite3* db;

};

class SQLiteDatabase : public Database
{
public:
SQLiteDatabase() = default;
~SQLiteDatabase() = default;

SQLiteDatabase(const std::string& dbname);

QueryResult query(const std::string& queryStr);

private:
SQLiteWrapper m_db;

};
} // namespace dppcord

#endif