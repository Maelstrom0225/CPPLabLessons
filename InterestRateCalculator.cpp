#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

double futureValue(double presentValue, double interestRate, int months) {
	return (presentValue * pow((1 + (interestRate)), months));
}

int main(){
	double presentValue, interestRate;
	int months;
	string file;
	ifstream inputFile;
	ofstream outputFile;	
	cout << "Enter input file name\n";
	cin >> file;
	inputFile.open(file);
	if (inputFile) {
		outputFile.open("output.xls");
		outputFile << "Future Value\tPresent Value\tMonthly Interest\tMonths\n";
		while (inputFile >> presentValue >> interestRate >> months) {
			interestRate = interestRate / 100.0000;
			outputFile << fixed << setprecision(2) << futureValue(presentValue, interestRate, months) << "\t" << presentValue << "\t" << setprecision(3) << interestRate*100.000 << "\t" << months << endl;
			cout << fixed << setprecision(2) << presentValue << " " << setprecision(3) << interestRate * 100 << " " << months << endl;
			if ((presentValue <= 0) || (interestRate <= 0) || (months <= 0))
				cout << "One or more of the above values are not greater than zero" << endl;
		}
	} else {
		cout << "File \"" << file << "\" could not be opened\n";
	}
	outputFile.close();
	inputFile.close();
}
