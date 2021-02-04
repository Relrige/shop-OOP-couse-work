#include "AdminFunction.h"
#include <mysql.h>


/// <summary>
/// menu for used function class
/// </summary>
void AdminFunction::menu()
{

	std::vector<std::string> list{ "Show category","Add accounts","Ban account","Unban account","Erase account","Changer password user","Add product","Erase product","Exit" };
	while (true) {
		size_t achion = 0;
		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < list.size(); i++) {
				if (i == achion) {
					Login::SetColor(0, 14);
				}
				if (i != achion) {
					Login::SetColor(0, 15);
				}
				std::cout << (*(list.begin() + i)) << std::endl;
				Login::SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 0) {
					achion = list.size();
				}
			}

			else if (a == 115) {
				achion++;
				if (achion > list.size()) {
					achion = 0;
				}
			}
		}
		std::cin.ignore();
		system("cls");
		if (achion == 0) {
			BaseFunctionForUsers::showCategory(1);
		}
		else if (achion == 1) {
			std::string login;
			std::string password;
			std::string role;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			std::cout << "Password ->";
			std::getline(std::cin, password);
			std::cout << "Role ->";
			std::getline(std::cin, role);
			addAccount(login, password, role);
		}
		else if (achion >= 2 &&achion <= 4) {

			std::string login;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			if (achion == 2)
				banAndUnBaneAccount(login);
			else if (achion == 3) {
				banAndUnBaneAccount(login,"1");
			}
			else
				eraseAccount(login);
		}
		else if (achion == 4) {
			std::string login;
			std::string password;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			std::cout << "Password ->";
			std::getline(std::cin, password);
			changeAccountPassword(login, password);
		}
		else if (achion == 5) {
			addProduct();
		}
		else if (achion == 6) {
			eraseProduct();
		}
		else if (achion == 7) {
			break;
		}
	}
}

/// <summary>
/// add account to DB
/// </summary>
/// <param name="login">login new account</param>
/// <param name="password">password new account</param>
/// <param name="role">role new account</param>
void AdminFunction::addAccount(const std::string& login, const std::string& password,const std::string role)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "INSERT INTO accounts(Id,login,password,role,activity) VALUES (1,\"login\",\""+password+"\",\""+role+"\",1);";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

/// <summary>
/// ban account by login
/// </summary>
/// <param name="login">login ban user</param>
void AdminFunction::banAndUnBaneAccount(const std::string& login,const std::string status)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "UPDATE "+Login::getTable()+"  SET activity = "+status.c_str()+" WHERE login = '" + login + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

/// <summary>
/// erase account by login
/// </summary>
/// <param name="login">login for erase</param>
void AdminFunction::eraseAccount(const std::string& login)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "DELETE FROM " + Login::getTable() + "  WHERE login = '" + login +"'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}
/// <summary>
/// change password for user
/// </summary>
/// <param name="login">user </param>
/// <param name="password">new password</param>
void AdminFunction::changeAccountPassword(const std::string& login, const std::string& password)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "UPDATE " + Login::getTable() + "  SET password = '"+password+"' WHERE login = '" + login + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

/// <summary>
/// add product in DB
/// </summary>
void AdminFunction::addProduct()
{
	BaseFunctionForUsers::showCategory(3);
}

/// <summary>
/// call function for choise product for erase
/// </summary>
void AdminFunction::eraseProduct()
{
	BaseFunctionForUsers::showCategory(2);
}

/// <summary>
/// erase product
/// </summary>
/// <param name="obj">obj for erase</param>
void AdminFunction::erase(Product* obj)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string table = typeid(*obj).name() + 6;
		table[0] = tolower(table[0]);
		std::string query = "DELETE FROM " + table + " WHERE name = '" + obj->getName().c_str() + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

/// <summary>
/// add product in vector
/// </summary>
/// <param name="name_category">name category </param>
/// <param name="list">vector products</param>
void AdminFunction::addInVector(const std::string& name_category, std::vector<Product*>& list)
{
	std::string command;
	std::string id;
	std::string name;
	std::string price;
	std::string countProduct;
	std::string grossWeigth;
	std::string guarantee;
	std::cout << "Id : ";
	std::getline(std::cin, id);
	std::cout << "Name : ";
	std::getline(std::cin, name);
	std::cout << "Price : ";
	std::getline(std::cin, price);
	std::cout << "Count of product : ";
	std::getline(std::cin, countProduct);
	std::cout << "Gross weigth : ";
	std::getline(std::cin, grossWeigth);
	std::cout << "Guarantee : ";
	std::getline(std::cin, guarantee);
	if (name_category == "Keyboard" or name_category == "Mice") {
		std::string color;
		std::string connection_type;
		std::string numberOfButtons;
		std::cout << "Color number : ";
		std::getline(std::cin, color);
		std::cout << "Connection type number : ";
		std::getline(std::cin, connection_type);
		std::cout << "Number of buttom : ";
		std::getline(std::cin, numberOfButtons);
		if (name_category == "Keyboard") {
			std::string keyboardType;
			std::string typeOfKeyboard;
			std::cout << "Keyboard type number : ";
			std::getline(std::cin, keyboardType);
			std::cout << "Type of keyboard number : ";
			std::getline(std::cin, typeOfKeyboard);
			command = "INSERT INTO keyboard(id, name, countProduct, price, grossWeigth, guarantee,maximumDisplayResolution,updateFrequency,displayDiagonal) VALUES(" + id + ",\"" + name + "\", " + countProduct + ", " + price + ", " + grossWeigth + ", " + guarantee + "," + keyboardType + "," + typeOfKeyboard + ");";
			list.push_back(new KeyBoard(id, name, countProduct, price, grossWeigth, guarantee, color, connection_type, numberOfButtons, keyboardType, typeOfKeyboard));
		}
		else {
			std::string sensor_type;
			std::cout << "Sensor type number : ";
			std::getline(std::cin, sensor_type);
			command = "INSERT INTO mice(id, name, countProduct, price, grossWeigth, guarantee, color, connection, sensorType, numberOfButtons) VALUES(1, \""+name+"\","+countProduct+","+price+","+grossWeigth+", "+guarantee+","+color+","+connection_type+", "+sensor_type+", "+numberOfButtons+");";
			list.push_back(new Mice(id, name, countProduct, price, grossWeigth, guarantee, color, connection_type, sensor_type, numberOfButtons));
			std::cout << *list.begin();
		}
	}
	else if (name_category == "Monitor" or name_category == "Laptop" or name_category == "PC" or name_category == "Console") {
		std::string displayDiagonal;
		std::string updateFrequency;
		std::string maximumDisplayResolution;
		if (name_category == "Monitor"&& name_category == "Laptop") {
		std::cout << "Maximum display resolutionr : ";
		std::getline(std::cin, maximumDisplayResolution);
		std::cout << "Update frequency : ";
		std::getline(std::cin, updateFrequency);
		std::cout << "Display diagonal : ";
		std::getline(std::cin,displayDiagonal);
		 if (name_category == "Monitor") {
			command = "INSERT INTO monitor(id, name, countProduct, price, grossWeigth, guarantee,maximumDisplayResolution,updateFrequency,displayDiagonal) VALUES(" + id + ",\"" + name + "\", " + countProduct + ", " + price + ", " + grossWeigth + ", " + guarantee + ",\"" + maximumDisplayResolution + "\",\"" + updateFrequency + "\", \"" + displayDiagonal+ "\");";
			list.push_back(new Monitor(id, name, countProduct, price, grossWeigth, guarantee, maximumDisplayResolution, updateFrequency, displayDiagonal));
		  }
		}
		else if (name_category == "PC" or name_category == "Laptop" or name_category == "Console") {
			std::string processor;
			std::string theAmountOfRAM;
			std::string videoCard;
			std::string preInstalledSoftware;
			std::cout << "Proccesor : ";
			std::getline(std::cin, processor);
			std::cout << "Video card : ";
			std::getline(std::cin, videoCard);
			std::cout << "The amount of RAM : ";
			std::getline(std::cin, theAmountOfRAM);
			std::cout << "Pre installed software : ";
			std::getline(std::cin, preInstalledSoftware);
			if (name_category == "PC") {
				command = "INSERT INTO pc(id, name, countProduct, price, grossWeigth, guarantee, processor, theAmountOfRAM, preInstalledSoftWare, videoCard) VALUES(" + id + ",\"" + name + "\", " + countProduct + ", " + price + ", " + grossWeigth + ", " + guarantee + ",\"" + processor + "\",\"" + theAmountOfRAM + "\", \"" + preInstalledSoftware + "\",\"" + videoCard + "\");";
				list.push_back(new PC(id, name, countProduct, price, grossWeigth, guarantee, processor, theAmountOfRAM, preInstalledSoftware, videoCard));
			}
			else if (name_category == "Console") {
				command = "INSERT INTO console(id, name, countProduct, price, grossWeigth, guarantee, processor, theAmountOfRAM, preInstalledSoftWare, videoCard) VALUES(" + id + ",\""+ name+"\", "+countProduct+", "+price+", "+grossWeigth+", "+guarantee+",\""+ processor+"\",\"" +theAmountOfRAM+"\", \""+preInstalledSoftware+"\",\""+videoCard+"\");";
				list.push_back(new Console(id, name, countProduct, price, grossWeigth, guarantee, processor, theAmountOfRAM, preInstalledSoftware, videoCard));
			}
			else {
				command = "INSERT INTO laptop(id, name, countProduct, price, grossWeigth, guarantee,maximumDisplayResolution,updateFrequency,displayDiagonal,processor, theAmountOfRAM, preInstalledSoftWare, videoCard) VALUES(" + id + ",\"" + name + "\", " + countProduct + ", " + price + ", " + grossWeigth + ", " + guarantee + ",\"" + processor + "\",\"" + theAmountOfRAM + "\", \"" + preInstalledSoftware + "\",\"" + videoCard + "\");";
				list.push_back(new Laptop(id, name, countProduct, price, grossWeigth, guarantee, maximumDisplayResolution, updateFrequency, displayDiagonal, processor, theAmountOfRAM, preInstalledSoftware, videoCard));
			}
		}
	}
	addInDB(command);
}

/// <summary>
/// add product in DB
/// </summary>
/// <param name="command">command muSQL</param>
void AdminFunction::addInDB(const std::string& command)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		const char* q = command.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

