#include "Medicine.h"

Medicine::Medicine()
{
    //default values
    m_title = new char[10] {"undefined"}; 
    m_type = TYPES::other;
    m_price = 0;
    m_country = new char[8] {"Ukraine"};
}

Medicine::Medicine(const char* title, TYPES type, float price, const char* country)
{
    int sizeTitle = strlen(title) + 1; //size
    m_title = new char[sizeTitle]; //выделение памяти
    strcpy_s(m_title, sizeTitle, title);

    m_type = type;
    m_price = price;

    int sizeCountry = strlen(country) + 1; //size
    m_country = new char[sizeCountry]; //выделение памяти
    strcpy_s(m_country, sizeCountry, country);
}

Medicine::Medicine(const Medicine& obj)
{
    int sizeT = strlen(obj.m_title) + 1;
    this->m_title = new char[sizeT];
    strcpy_s(this->m_title, sizeT, obj.m_title);

    this->m_type = obj.m_type;
    this->m_price = obj.m_price;

    int sizeC = strlen(obj.m_country) + 1;
    this->m_country = new char[sizeC];
    strcpy_s(this->m_country, sizeC, obj.m_country);
}

Medicine& Medicine::operator=(const Medicine& obj)
{
    this->~Medicine(); //!

    int sizeT = strlen(obj.m_title) + 1;
    this->m_title = new char[sizeT];
    strcpy_s(this->m_title, sizeT, obj.m_title);

    this->m_type = obj.m_type;
    this->m_price = obj.m_price;

    int sizeC = strlen(obj.m_country) + 1;
    this->m_country = new char[sizeC];
    strcpy_s(this->m_country, sizeC, obj.m_country);

    return *this;
}

Medicine::~Medicine()
{
    delete[] m_title;
    delete[] m_country;
}

void Medicine::setTitle(const char* title)
{
    if (strlen(title) >= 2) {
        delete[] m_title; //delete old title

        int sizeTitle = strlen(title) + 1; //size
        m_title = new char[sizeTitle]; //выделение памяти
        strcpy_s(m_title, sizeTitle, title);
    }
}

void Medicine::setType(TYPES type)
{
    m_type = type;
}

void Medicine::setPrice(float price)
{
    if (price > 0) {
        m_price = price;
    }
}

void Medicine::setCountry(const char* country)
{
    if (strlen(country) >= 2) {
        delete[] m_country; //delete old title

        int sizeCountry = strlen(country) + 1; //size
        m_country = new char[sizeCountry]; //выделение памяти
        strcpy_s(m_country, sizeCountry, country);
    }
}

const char* Medicine::getTitle() const{return m_title;}

TYPES Medicine::getType() const{return m_type;}

float Medicine::getPrice() const{return m_price;}

const char* Medicine::getCountry() const{return m_country;}

void Medicine::showInfo() const
{
    cout << "Title: " << m_title << endl;
    cout << "Type: ";
    switch (m_type)
    {
    case other:
        cout << "Other" << endl;
        break;
    case pills:
        cout << "Pills" << endl;
        break;
    case capsules:
        cout << "Capsules" << endl;
        break;
    case syrop:
        cout << "Syrop" << endl;
        break;
    default:
        break;
    }
    cout << "Price: " << m_price << " UAH" << endl;
    cout << "Country: " << m_country << endl;
    cout << endl;
}
