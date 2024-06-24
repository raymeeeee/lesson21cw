#pragma once
#include <iostream>
using namespace std;

enum TYPES {
	other,		//0
	pills = 1,
	capsules,	//2
	syrop		//3
};

class Medicine
{
	char* m_title;
	TYPES m_type;
	float m_price;
	char* m_country;

public:

	Medicine();
	Medicine(const char* title, TYPES type, float pricem, const char* country);
	Medicine(const Medicine& obj); //!! copy constructor
	Medicine& operator = (const Medicine& obj); //!! operator= присвоювання
	~Medicine();

	void setTitle(const char* title);
	void setType(TYPES type);
	void setPrice(float price);
	void setCountry(const char* country);

	const char* getTitle()const; //!! константный метод
	TYPES getType()const;
	float getPrice()const;
	const char* getCountry()const;

	void showInfo()const;

};

