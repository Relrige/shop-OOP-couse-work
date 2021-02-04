#pragma once
#include<iostream>
#include<string>
#include<vector>

/// <summary>
/// base class for products
/// </summary>
class Product abstract
{
public:
	Product(const std::string& id,const std::string& name,const std::string& countProduct,const std::string& price,const std::string& grossWeigth,const std::string& guarantee);
	virtual bool InStoke() const;
	void setId(const std::string& id);
	void setName(const std::string& name);
	void setCountProduct(const std::string& countProduct);
	void setGuarantee(const std::string& guarantee);
	void setGrossWeigth(const std::string& grossWeigth);
	void setPrice(const std::string& price);
	virtual void print() const = 0;
	const std::string& getName() const;
	const float& getPrice() const;
	const size_t& getCountProduct() const;
	friend std::ostream& operator<<(std::ostream& os, const Product& obj);
protected:
	std::string id;
	std::string name;
	float price;
	size_t countProduct;
	size_t grossWeigth;
	size_t guarantee;
};

class ComputerComponents : public Product
{
public:
	ComputerComponents(const std::string& id,const std::string& name,const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& conection,const std::string numberOfButtons);
	void setColor(const std::string& color);
	void setConnectionType(const std::string& connection_type);
	void setCountOfButtons(const std::string& numberOfButtons);

protected:
	std::vector<std::string> color_list{"White","Brown","Pink","Multicolored","Blue","Silver","Gray","Red","Black" };
	std::vector<std::string> connection_type_list{"Wireless","Wires","Wires+Cords"};
	std::string color;
	std::string connection_type;
	size_t numberOfButtons;
};

class Mice : public ComputerComponents
{
public:
	Mice(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& connection,const std::string& sensorType, const std::string numberOfButtons);
	void setSensorType(const std::string& sensorType);
	void print()const override;
public:
	std::vector<std::string> sensor_type_list{"Laser","Optical"};
	std::string sensor_type;
};

class KeyBoard : public ComputerComponents
{
public:
	KeyBoard(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& color, const std::string& connection, const std::string numberOfButtonsconst,const std::string& keyboardType,const std::string& typeOfKeyboard);
	void setKeyboardType(const std::string& keyboardType);
	void setTypeOfKeyboard(const std::string& typeOfKeyboard);
	void print()const override;
private:
	std::string keyboardType;
	std::string typeOfKeyboard;
	std::vector<std::string> typeOfKeyboard_list{ "Game","Multimedia","Mini keyboard","Standard" };
	std::vector<std::string> keyboardType_list{ "Hybrid mechanical - membrane","Combined membrane + mechanical","Membranes","Mechanical","Scissors","Optical - mechanical" };

};

class Monitor :virtual public Product
{
public:
	Monitor(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee,const std::string& maximumDisplayResolution,const std::string& updateFrequency, const std::string& displayDiagonal);
	void setMaximumDisplayResolution(const std::string& maximumDisplayResolution);
	void setUpdateFrequency(const std::string& updateFrequency);
	void setDisplayDiagonal(const std::string& displayDiagonal);
	void print()const override;
protected:
	float displayDiagonal;
	size_t updateFrequency;
	std::string maximumDisplayResolution;
};

class PC :virtual public Product
{
public:
	PC(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard);
	void setProcessor(const std::string& processor);
	void setTheAmountOfRAM(const std::string& theAmountOfRAM);
	void setVideoCard(const std::string videoCard);
	void setPreInstalledSoftWare(const std::string preInstalledSoftWare);
	void print()const override;
protected:
	std::string processor;
	std::string theAmountOfRAM;
	std::string videoCard;
	std::string preInstalledSoftware;
};

class Laptop :virtual public Monitor,virtual public PC
{
public:
	Laptop(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& maximumDisplayResolution, const std::string& updateFrequency, const std::string& displayDiagonal, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard);
	void print()const override;
};

class Console : public PC 
{
public:
	Console(const std::string& id, const std::string& name, const std::string& countProduct, const std::string& price, const std::string& grossWeigth, const std::string& guarantee, const std::string& processor, const std::string& theAmountOfRAM, const std::string& preInstalledSoftWare, const std::string& videoCard);
	void print()const override;
};