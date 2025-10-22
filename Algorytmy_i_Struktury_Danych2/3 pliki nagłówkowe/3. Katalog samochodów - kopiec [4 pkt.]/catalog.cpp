#include "catalog.h"

Catalog::Catalog() {
	carsSize = 0;
}

int Catalog::heapMinChild(int parent) {
	int child = parent * 2;
	if (child > carsSize) return 0;
	if (child + 1 > carsSize) return child;

	if (cars[child].getMoc() < cars[child + 1].getMoc() || (cars[child].getMoc() == cars[child + 1].getMoc() && cars[child].getWaga() < cars[child + 1].getWaga()))
		return child;
	else
		return child + 1;
}

void Catalog::heapRemoveMin() {
	if (carsSize == 0) return;

	cars[1] = cars[carsSize--];
	int parent = 1;
	int child = heapMinChild(parent);

	while (child != 0 && (cars[parent].getMoc() > cars[child].getMoc() || (cars[parent].getMoc() == cars[child].getMoc() && cars[parent].getWaga() > cars[child].getWaga()))) {
		Car temp = cars[parent];
		cars[parent] = cars[child];
		cars[child] = temp;

		parent = child;
		child = heapMinChild(parent);
	}
}

void Catalog::addCar(Car& dane) {
	int child = ++carsSize;
	int parent = child / 2;

	while (parent && (cars[parent].getMoc() > dane.getMoc() || (cars[parent].getMoc() == dane.getMoc() && cars[parent].getWaga() > dane.getWaga()))) {
		cars[child] = cars[parent];
		child = parent;
		parent /= 2;
	}
	cars[child] = dane;
}

void Catalog::displayLicenseAndPower() {
	for (int i = 1; i < 7; i++) {
		cout << cars[1].getNumer() << " " << cars[1].getMoc() << " ";
		heapRemoveMin();
	}
}