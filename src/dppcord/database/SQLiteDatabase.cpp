/**
 * @file SQLiteDatabase.cpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-02 11:13
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dppcord/database/SQLiteDatabase.hpp"

#include <iostream>

namespace dppcord
{

SQLiteDatabase::SQLiteDatabase(const std::string &dbname)
{
    sqlite3 *db = nullptr;
    auto ec = sqlite3_open(dbname.c_str(), &db);
    if (ec)
    {
        std::cout << "Can't open database.\n";
        sqlite3_close(db);
        return;
    }
    m_db.db = db;
}

const QueryResult SQLiteDatabase::query(const std::string &queryStr)
{
    sqlite3_stmt* stmt;
    auto ec = sqlite3_prepare_v2(m_db.db, queryStr.c_str(), -1, &stmt, NULL);
    if(ec != SQLITE_OK)
    {
        std::cout << "Error while executing query\n";
        return {};
    }
    QueryResult result;
    while((ec = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::map<std::string,std::string> row;
        const int colCount = sqlite3_column_count(stmt);

        for(int col = 0;col<colCount;col++)
        {
            row[sqlite3_column_name(stmt, col)] = reinterpret_cast<const char*>(sqlite3_column_text(stmt, col));
        }
        result.push_back(row);
    }

    if(ec != SQLITE_DONE)
    {
        std::cout << "???\n";
        return result;
    }
    sqlite3_finalize(stmt);
    return result;
}
} // namespace dppcord