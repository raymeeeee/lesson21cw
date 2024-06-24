#include "Pharmacy.h"

int main()
{
	Medicine a;
	Medicine b("Aspirin", TYPES::pills, 20.55, "India");
	const Medicine c("Nurofen", TYPES::syrop, 26.85, "Poland");

	a.showInfo();
	b.showInfo();
	c.showInfo();

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;

	Medicine e = b; //copy
	//e-this = b-obj
	e.setTitle("Test");

	b.showInfo();
	e.showInfo();

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;


	a = c; //operator=
	a.setCountry("France");

	a.showInfo();
	c.showInfo();

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;


}