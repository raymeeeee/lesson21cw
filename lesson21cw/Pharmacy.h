#pragma once
#include "ArrayTemplate 4.h"
#include "Medicine.h"

class Pharmacy
{
	char m_name[50];
	int m_sizeMedicine;
	Medicine* m_arrMedicine;
	
public:

	Pharmacy();
	Pharmacy(const char* name);
	~Pharmacy();

	void setName(const char* name);

	const char* getName()const;

	void addMedicine(Medicine obj);

	void showInfo()const;

};

