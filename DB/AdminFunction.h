#pragma once
#include "Login.h"
#include"BaseFunctionForUsers.h"
#include <string>

class AdminFunction 
{
public:
	static void menu();
	static void addAccount(const std::string& login, const std::string& password, const std::string role);
	static void banAndUnBaneAccount(const std::string& login,std::string status = 0);
	static void eraseAccount(const std::string& login);
	static void changeAccountPassword(const std::string& login, const std::string& password);
	static void addProduct();
	static void eraseProduct();
	static void erase(Product* obj);
	static void addInVector(const std::string& name_category,std::vector<Product*>& list);
	static void addInDB(const std::string& command);
};

