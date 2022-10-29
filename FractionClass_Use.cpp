#include <iostream>
#include <climits>

using namespace std;

#include "FractionClass.cpp"

int main(){


	int numerator1;
	cout << "Enter the numerator of the first fraction: ";
	cin >> numerator1;

	int numerator2;
	cout << "Enter the numerator of the second fraction: ";
	cin >> numerator2;

	int denominator1;
	cout << "Enter the denominator of the first fraction: ";
	cin >> denominator1;

	int denominator2;
	cout << "Enter the denominator of the first fraction: ";
	cin >> denominator2;

	Fraction f1(numerator1, denominator1);
	Fraction f2(numerator2, denominator2);

	cout << "The first fraction is: ";
	f1.Print();

	cout << "The second fraction is: ";
	f2.Print();

	f2.Add(f1);

	cout << endl << "The addition of the fractions result in a simplified fraction that cannot be simplified any further: ";
	f2.Print();
}