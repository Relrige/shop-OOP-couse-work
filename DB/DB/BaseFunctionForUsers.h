#pragma once
#include<vector>
#include"CategotiesClass.h"
#include"windows.h"
#include<iostream>
#include<algorithm>
#include <mysql.h>
#include<conio.h>
#include"windows.h"
#include"Login.h"

class BaseFunctionForUsers
{
public:
	static void getAllProductsCategory( std::string& nameTable, const size_t& number_achion);
	static void showProduct(Product* obj);
	static void buyProduct( Product* obj);
	static void showAllProductsCategory(std::vector<Product*>& list, const size_t& number_achion);
	static void showCategory(const size_t& number_achion );
	static void SortBy( std::vector<Product*>& list);

};

