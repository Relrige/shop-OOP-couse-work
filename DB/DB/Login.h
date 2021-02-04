#pragma once
#include <mysql.h>
#include <iostream>
#include "AdminFunction.h"
#include "UserFunction.h"
#include"Lib.h"

class Login
{
public:
	static void SetColor(int text, int bg);
	enum class ROLE_LIST{USER,ADMIN,UNDEFINED};
	static void menu();
	static size_t getRole();
	static std::string getDB();
	static std::string getHost();
	static std::string getUser();
	static std::string getPass();
	static std::string getTable();
	static unsigned int getPort();
private:
	static bool isTrueSingIn(const std::string& login,const std::string& password);
	static ROLE_LIST role;
	static size_t counterIncorectPassword;
	static std::string user;
	static std::string pass;
	static std::string host;
	static std::string DB;
	static std::string table;
	static int port;
};

