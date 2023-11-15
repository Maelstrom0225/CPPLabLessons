#include <iostream>
#include <iomanip>
using namespace std;

/*
This lab lesson you are writing a program for the hypothetical Acme Wholesale Copper Wire Company. 
The Acme company sells spools of copper wiring for $104 each. 
Write a program that displays the status of an order.
*/

void display(int orderedSpools, int stockedSpools, double shippingAndHandling) {
	int readyToShip = orderedSpools;
	int backOrder = 0;
	double price = 104;
	// Not Enough in Stock
	if (stockedSpools < orderedSpools) {
		readyToShip = stockedSpools;
		backOrder = orderedSpools - stockedSpools;
	}
	// Cout's
	cout << "Spools ready to ship: " << readyToShip;
	cout << endl << "Spools on back-order: " << backOrder;
	cout << fixed << setprecision(2);
	cout << endl << "Subtotal ready to ship: $" << setw(10) << readyToShip * price;
	cout << endl << "Shipping and handling:  $" << setw(10) << shippingAndHandling * readyToShip;
	cout << endl << "Total shipping charges: $" << setw(10) << readyToShip * (price + shippingAndHandling);
	cout << endl;

}

void readIn(int &orderedSpools, int &stockedSpools, double &shippingAndHandling) {
	char specialOrder;
	// Spool Order
	cout << "Spools to be ordered" << endl;
	cin >> orderedSpools;
	while (orderedSpools < 1) {
		cout << "Spools order must be 1 or more" << endl;
		cout << "Spools to be ordered" << endl;
		cin >> orderedSpools;
	}
	// Spools in Stock
	cout << "Spools in stock" << endl;
	cin >> stockedSpools;
	while (stockedSpools < 0) {
		cout << "Spools in stock must be 0 or more" << endl;
		cout << "Spools in stock" << endl;
		cin >> stockedSpools;
	}
	// Special Order
	cout << "Special shipping and handling (y or n)" << endl;
	cin >> specialOrder;
	if ((specialOrder == 'y') || (specialOrder == 'Y')) {
		cout << "Shipping and handling amount" << endl;
		cin >> shippingAndHandling;
		while (shippingAndHandling < 0) {
			cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
			cout << "Shipping and handling amount" << endl;
			cin >> shippingAndHandling;
		}
	}
}

int main() {
	int orderedSpools, stockedSpools;
	double shippingAndHandling = 12.99;
	readIn(orderedSpools, stockedSpools, shippingAndHandling);
	display(orderedSpools, stockedSpools, shippingAndHandling);
}