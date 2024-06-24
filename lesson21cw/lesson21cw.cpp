#include "Pharmacy.h"

int main()
{
	Medicine a;
	Medicine b("Aspirin", TYPES::pills, 20.55, "India");
	const Medicine c("Nurofen", TYPES::syrop, 26.85, "Poland");

	Medicine e = b; //copy
	//e-this = b-obj
	e.setTitle("Aspirin Forte");

	a = c; //operator=
	a.setCountry("France");

	Pharmacy pharm("119");
	pharm.addMedicine(a);
	pharm.addMedicine(b);
	pharm.addMedicine(c);
	pharm.addMedicine(e);
	pharm.addMedicine(Medicine("Analgin", TYPES::capsules, 30.20, "India"));

	pharm.showInfo();

}