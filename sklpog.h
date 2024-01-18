#ifndef SKLPOG_H
#define SKLPOG_H
#include <string>

bool checkLoginAndPassword(const std::string& tableName, const std::string& login, const std::string& password, const std::string& dbPath);
bool createAccount(const std::string& tableName,const std::string& email, const std::string& login, const std::string& password, const std::string& dbPath);
bool checkPassword(const std::string& email);
#endif // SKLPOG_H
