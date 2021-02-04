#include"CategotiesClass.h"

/// <summary>
/// ctor for class Product
/// </summary>
/// <param name="id">id product from DB</param>
/// <param name="name">name product from DB</param>
/// <param name="countProduct">count product from DB</param>
Product::Product(const std::string& id,const std::string& name,const std::string& countProduct,const std::string& price,const std::string& grossWeigth, const std::string& guarantee) {
	setName(name);
	setCountProduct(countProduct);
	setId(id);
	setPrice(price);
	setGuarantee(guarantee); 
	setGrossWeigth(grossWeigth);
}

/// <summary>
/// stock products
/// </summary>
/// <returns>is in stosk</returns>
bool Product::InStoke() const {
	return countProduct != 0;
}

/// <summary>
/// set for id
/// </summary>
/// <param name="id">id from Data base</param>
void Product::setId(const std::string& id) {
	try {
		size_t temp_id = std::stoi(id);
		this->id = id;
		return;
	}catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad id" << std::endl;
	}
	this->id = "bad id";
}

/// <summary>
/// set for name
/// </summary>
/// <param name="name">name from Data base</param>
void Product::setName(const std::string& name) {
	if (!name.empty()){
		this->name = name;
		return;
	}
	this->name = "Bad name";
}

/// <summary>
/// set for countProduct
/// </summary>
/// <param name="name">name from Data base</param>
void Product::setCountProduct(const std::string& countProduct) {
	try {
		this->countProduct = std::stoi(countProduct);
		if(this->countProduct >= 0)
		return;
		throw std::invalid_argument(countProduct);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad count "<<countProduct<< std::endl;
	}
	this->countProduct = 0;
}

void Product::setGuarantee(const std::string& guarantee)
{
	try {
		this->guarantee = std::stoi(guarantee);
		if (this->guarantee >= 0)
			return;
		throw std::invalid_argument(guarantee);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad guarantee " << guarantee << std::endl;
	}
	this->grossWeigth = 0;
}

void Product::setGrossWeigth(const std::string& grossWeigth)
{
	try {
		this->grossWeigth = std::stoi(grossWeigth);
		if (this->grossWeigth >= 0)
			return;
		throw std::invalid_argument(grossWeigth);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad gross weigth " << grossWeigth << std::endl;
	}
	this->grossWeigth = 0;
}

void Product::setPrice(const std::string& price)
{
	try {
		this->price = std::stof(price);
		if (this->price >= 0)
			return;
		throw std::invalid_argument(price);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad price " << price << std::endl;
	}
	this->price = 0;
}



const std::string& Product::getName() const
{
	return name;
}

const float& Product::getPrice() const
{
	return price;
}

const size_t& Product::getCountProduct() const
{
	return countProduct;
}

ComputerComponents::ComputerComponents(const std::string& id,const std::string& name,const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& conection, const std::string numberofButtons) : Product(id,name,countProduct,price,grossWeigth,guarantee)
{
	setColor(color);
	setCountOfButtons(numberofButtons);
}

void ComputerComponents::setColor(const std::string& color)
{
	size_t tempIndex;
	try {
		tempIndex = std::stoi(color);
		if (tempIndex >= 0 && tempIndex <= color_list.size()) {
			this->color = *(color_list.begin() + tempIndex);
			return;
		}
		throw std::invalid_argument(color);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << " have bad color  " << color << std::endl;
	}
	this->color = "have bad color";
}

void ComputerComponents::setConnectionType(const std::string& connection_type)
{
	try {
		size_t tempIndex = stoi(connection_type);
		this->connection_type = *(connection_type_list.begin()+tempIndex);
		return;
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad connection type " << connection_type << std::endl;
	}
	this->connection_type = "bad connection type";
}

void ComputerComponents::setCountOfButtons(const std::string& numberOfButtons)
{
	try {
		this->numberOfButtons = std::stoi(numberOfButtons);
		if (this->numberOfButtons >= 0)
			return;
		throw std::invalid_argument(numberOfButtons);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad number of buttons " << numberOfButtons << std::endl;
	}
	this->numberOfButtons = 0;
}

Mice::Mice(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& connection, const std::string& sensorType, const std::string numberOfButtons) : ComputerComponents(id, name, countProduct, price, grossWeigth, guarantee,color,connection,numberOfButtons)
{
	setConnectionType(connection);
	setSensorType(connection);
}

void Mice::setSensorType(const std::string& sensorType)
{
	size_t tempIndex;
	try {
		tempIndex = std::stoi(sensorType);
		if (tempIndex >= 0 && tempIndex <= sensor_type_list.size()) {
			this->sensor_type = *(sensor_type_list.begin() + tempIndex);
		}
		return;
		throw std::invalid_argument(sensorType);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad sensor type " << sensorType << std::endl;
	}
	this->sensor_type = "bad sensor type";
}

void Mice::print() const
{
	std::cout << "Name : " << name<<std::endl;
	std::cout << "Price : " << price << std::endl;
	std::cout << "Number of botton : " << numberOfButtons << std::endl;
	std::cout << "Color : " << color << std::endl;
	std::cout << "Type connection : " << connection_type << std::endl;
	std::cout << "Sensor type : " << sensor_type << std::endl;
	std::cout << "Gross weight : " << grossWeigth << std::endl;
	std::cout << "Guarantee : " << guarantee << " month" << std::endl;
	std::cout << "Count : " << countProduct << std::endl;

}

KeyBoard::KeyBoard(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& connection, const std::string numberOfButtons, const std::string& keyboardType, const std::string& typeOfKeyboard) : ComputerComponents(id, name, countProduct, price, grossWeigth, guarantee, color, connection, numberOfButtons)
{
	setConnectionType(connection);
	setKeyboardType(keyboardType);
	setTypeOfKeyboard(typeOfKeyboard);
}

void KeyBoard::setKeyboardType(const std::string& keyboardType)
{
	size_t tempIndex;
	try {
		tempIndex = std::stoi(keyboardType);
		if (tempIndex >= 0 && tempIndex <= keyboardType_list.size()) {
			this->keyboardType = *(keyboardType_list.begin() + tempIndex);
		}
		return;
		throw std::invalid_argument(keyboardType);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad  keyboard type " << keyboardType << std::endl;
	}
	this->keyboardType = "bad keyboard type";
}

void KeyBoard::setTypeOfKeyboard(const std::string& typeOfKeyboard)
{
	size_t tempIndex;
	try {
		tempIndex = std::stoi(typeOfKeyboard);
		if (tempIndex >= 0 && tempIndex <= typeOfKeyboard.size()) {
			this->typeOfKeyboard = *(typeOfKeyboard_list.begin() + tempIndex);
		}
		return;
		throw std::invalid_argument(typeOfKeyboard);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "type of keyboard " << typeOfKeyboard << std::endl;
	}
	this->typeOfKeyboard = "bad type of keyboard";
}

void KeyBoard::print() const
{
	std::cout << "Name : " << name << std::endl;
	std::cout << "Price : " << price << std::endl;
	std::cout << "Number of botton : " << numberOfButtons << std::endl;
	std::cout << "Color : " << color << std::endl;
	std::cout << "Type connection : " << connection_type << std::endl;
	std::cout << "Keyboard type : " << keyboardType << std::endl;
	std::cout << "Type of keyboard : " << typeOfKeyboard << std::endl;
	std::cout << "Gross weight : " << grossWeigth << std::endl;
	std::cout << "Guarantee : " << guarantee << " month" << std::endl;
	std::cout << "Count : " << countProduct << std::endl;
}

Monitor::Monitor(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& maximumDisplayResolution, const std::string& updateFrequency, const std::string& displayDiagonal) : Product(id, name, countProduct, price, grossWeigth, guarantee)
{
	setUpdateFrequency(updateFrequency);
	setDisplayDiagonal(displayDiagonal);
	setMaximumDisplayResolution(maximumDisplayResolution);
}

void Monitor::print()  const
{
	std::cout << "Name : " << name << std::endl;
	std::cout << "Price : " << price << std::endl;
	std::cout << "Display diagonal : " << displayDiagonal << std::endl;
	std::cout << "Maximum display resolution : " << maximumDisplayResolution << std::endl;
	std::cout << "Update frequency : " <<updateFrequency << std::endl;
	std::cout << "Gross weight : " << grossWeigth << std::endl;
	std::cout << "Guarantee : " << guarantee << " month" << std::endl;
	std::cout << "Count : " << countProduct << std::endl;

}

void PC::print() const
{
	std::cout << "Name : " << name << std::endl;
	std::cout << "Price : " << price << std::endl;
	std::cout << "Processor : " << processor << std::endl;
	std::cout << "RAM : " << theAmountOfRAM << std::endl;
	std::cout << "Pre installed software : " <<preInstalledSoftware << std::endl;
	std::cout << "Video card : " <<videoCard << std::endl;
	std::cout << "Gross weight : " << grossWeigth << std::endl;
	std::cout << "Guarantee : " << guarantee << " month" << std::endl;
	std::cout << "Count : " << countProduct << std::endl;

}

void Console::print() const
 {
	std::cout << "Name : " << name << std::endl;
	std::cout << "Price : " << price << std::endl;
	std::cout << "Processor : " << processor << std::endl;
	std::cout << "RAM : " << theAmountOfRAM << std::endl;
	std::cout << "Pre installed software : " <<preInstalledSoftware << std::endl;
	std::cout << "Video card : " <<videoCard << std::endl;
	std::cout << "Gross weight : " << grossWeigth << std::endl;
	std::cout << "Guarantee : " << guarantee << " month" << std::endl;
	std::cout << "Count : " << countProduct << std::endl;

}
void Laptop::print()  const
{
	std::cout << "Name : " << PC::name << std::endl;
	std::cout << "Price : " << PC::price << std::endl;
	std::cout << "Processor : " << processor << std::endl;
	std::cout << "RAM : " << theAmountOfRAM << std::endl;
	std::cout << "Video card : " << videoCard << std::endl;
	std::cout << "Display diagonal : " << displayDiagonal << std::endl;
	std::cout << "Maximum display resolution : " << maximumDisplayResolution << std::endl;
	std::cout << "Update frequency : " << updateFrequency << std::endl;
	std::cout << "Pre installed software : " << preInstalledSoftware << std::endl;
	std::cout << "Gross weight : " << PC::grossWeigth << std::endl;
	std::cout << "Guarantee : " << PC::guarantee << " month" << std::endl;
	std::cout << "Count : " << PC::countProduct << std::endl;

}
void PC::setVideoCard(const std::string videoCard)
{
	if (!videoCard.empty()) {
		this->videoCard = videoCard;
	}
	else {
		this->videoCard = "bad video card";
	}
}
void Monitor::setDisplayDiagonal(const std::string& displayDiagonal)
{
	try {
		this->displayDiagonal = std::stof(displayDiagonal);
		if (this->displayDiagonal > 0)
			return;
		throw std::invalid_argument(displayDiagonal);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad display diagonal  " << displayDiagonal << std::endl;
	}
	this->displayDiagonal = 0;
}

void Monitor::setMaximumDisplayResolution(const std::string& maximumDisplayResolution)
{
	if (!maximumDisplayResolution.empty()) {
		this->maximumDisplayResolution = maximumDisplayResolution;

	}
	else {
		std::cerr << "Product " << name << "have bad maximum display resolution  " << maximumDisplayResolution << std::endl;
		this->maximumDisplayResolution = "bad maximum display resolution";
	}
}



void PC::setProcessor(const std::string& processor)
{
	if (!processor.empty()) {
		this->processor = processor;
	}
	else {
		this->processor = "bad processor";
	}
}

void PC::setTheAmountOfRAM(const std::string& theAmountOfRAM)
{
	if (!theAmountOfRAM.empty()) {
		this->theAmountOfRAM = theAmountOfRAM;
	}
	else {
		this->theAmountOfRAM = "bad the amount of RAM";
	}
}

PC::PC(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard) : Product(id, name, countProduct, price, grossWeigth, guarantee)
{
	setPreInstalledSoftWare(preInstalledSoftWare);
	setTheAmountOfRAM(theAmountOfRAM);
	setProcessor(processor);
	setVideoCard(videoCard);
}

void PC::setPreInstalledSoftWare(const std::string preInstalledSoftWare)
{
	if (!preInstalledSoftWare.empty()) {
		this->preInstalledSoftware = preInstalledSoftWare;
		return;
	}
	else {
		this->preInstalledSoftware = "bad pre installed SoftWare";
	}
}

void Monitor::setUpdateFrequency(const std::string& updateFrequency)
{
	try {
		this->updateFrequency = std::stoi(updateFrequency);
		if (this->updateFrequency > 0)
			return;
		throw std::invalid_argument(updateFrequency);
	}
	catch (std::invalid_argument) {
		std::cerr << "Product " << name << "have bad update frequency  " << updateFrequency << std::endl;
	}
	this->updateFrequency = 0;
}

Laptop::Laptop(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& maximumDisplayResolution, const std::string& updateFrequency, const std::string& displayDiagonal, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard) : Monitor("", "", "", "", "", "", maximumDisplayResolution,updateFrequency,displayDiagonal),PC("","", "", "","","",processor,theAmountOfRAM,preInstalledSoftWare,videoCard), Product(id, name, countProduct, price, grossWeigth, guarantee)
{

}

Console::Console(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard) : PC(id, name, countProduct, price, grossWeigth, guarantee, processor, theAmountOfRAM, preInstalledSoftWare, videoCard), Product(id, name, countProduct, price, grossWeigth, guarantee)
{

}

std::ostream& operator<<(std::ostream& os, const Product& obj)
{
	os << "\t" << "Name : " << obj.name << "\t" <<"Price : "<<obj.price<<"\t"<< "Count product : " << obj.countProduct << "\t" << std::endl;
	return os;
}
