#include "Pharmacy.h"

Pharmacy::Pharmacy()
{
	strcpy_s(m_name, 50, "911");
	m_sizeMedicine = 0;
	m_arrMedicine = nullptr;
}

Pharmacy::Pharmacy(const char* name)
{
	strcpy_s(m_name, 50, name);
	m_sizeMedicine = 0;
	m_arrMedicine = nullptr;
}

Pharmacy::~Pharmacy()
{
	if (m_arrMedicine != nullptr) {
		delete[] m_arrMedicine;
	}
}

void Pharmacy::setName(const char* name)
{
	if (strlen(name) >= 2) {
		strcpy_s(m_name, 50, name);
	}
}

const char* Pharmacy::getName() const
{
	return m_name;
}

void Pharmacy::addMedicine(Medicine obj)
{
	addItemBack(m_arrMedicine, m_sizeMedicine, obj);
}

void Pharmacy::showInfo() const
{
	cout << "Name: " << m_name << endl << endl;
	if (m_sizeMedicine == 0) {
		cout << "Pharmacy has no medicine" << endl;
	}
	else {
		for (int i = 0; i < m_sizeMedicine; i++)
		{
			cout << "\t#" << i + 1 << " Medicine" << endl;
			m_arrMedicine[i].showInfo();
		}
	}
}

void Pharmacy::findMedicine_title(const char* title)
{
	for (int i = 0; i < m_sizeMedicine; i++)
	{
		if (strcmp(title, m_arrMedicine[i].getTitle()) == 0) {
			m_arrMedicine[i].showInfo();
			return;
		}
	}	
	cout << "Not found" << endl << endl;
}

void Pharmacy::sort_price()
{
	sort_if<Medicine>(m_arrMedicine, m_sizeMedicine,
		[](Medicine left, Medicine right) {return left.getPrice() < right.getPrice(); });
}

void Pharmacy::sort_title()
{
	sort_if<Medicine>(m_arrMedicine, m_sizeMedicine,
		[](Medicine left, Medicine right) {return strcmp(left.getTitle(), right.getTitle())	> 0; }); //from a-z
}
