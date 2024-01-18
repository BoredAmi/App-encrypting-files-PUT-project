#include "sklpog.h"
#include <iostream>
#include <sqlite3.h>
#include <cctype>
#include <libcryptsetup.h>
#include <cryptopp/aes.h>
#include <cryptopp/sha3.h>
using namespace CryptoPP;

bool checkLoginAndPassword(const std::string& tableName, const std::string& login, const std::string& password, const std::string& dbPath) {
    sqlite3 *db;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Error opening the database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    std::string query = "SELECT * FROM " + tableName + " WHERE login = ? AND password = ?";

    std::string digest;
    SHA3_256 hash;
    hash.Update((const byte*)password.data(), password.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing the query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, digest.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "Login and password match a row in the table." << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return true;
    } else {
        std::cout << "Login and password do not match any row in the table." << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }
}

bool createAccount(const std::string& tableName, const std::string& email,const std::string& login, const std::string& password, const std::string& dbPath) {
    sqlite3 *db;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Error opening the database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::string digest;
    SHA3_256 hash;
    hash.Update((const byte*)password.data(), password.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);


    std::string query = "INSERT INTO " + tableName + " (login, password, email) VALUES (?, ?, ?)";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing the query: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, digest.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return false;
    }

    std::cout << "Account created successfully." << std::endl;

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return true;
}
bool checkPassword(const std::string &email)
{
    bool s,u,l,n;
    for (char ch : email)
    {
        if (std::ispunct(ch))
        {
            s=true;
            break;
        }
        s = false;
    }
    for (char ch : email)
    {
        if (std::isdigit(ch))
        {
            n=true;
            break;
        }
        n = false;
    }
    for (char ch : email)
    {
        if (std::isupper(ch))
        {
            u =true;
            break;
        }
        u = false;
    }
    for (char ch : email)
    {
        if (std::islower(ch))
        {
            l=true;
            break;
        }
        l = false;
    }
    if(n && l && u && s)
    {
        return true;
    }
    else
    {
        return false;
    }

}
