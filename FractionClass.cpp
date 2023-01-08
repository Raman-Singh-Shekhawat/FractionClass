#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;


class Fraction{


	public:

	int numerator;
	int denominator;


	// Used As A Default Constructor
	Fraction(){

	}


	void Simplify(){

	
		int upTo = min(this -> numerator, this -> denominator);
		int  UseSimplify = 1;		

		for(int i = 1; i <= upTo; i++){


			if(this -> numerator % i == 0 && this -> denominator % i == 0){


				UseSimplify = i;
			}
		}

		this -> numerator = this -> numerator / UseSimplify;
		this -> denominator = this -> denominator / UseSimplify;
	}

	Fraction(int numerator, int denominator){


		this -> numerator = numerator;
		this -> denominator = denominator;
	}

	Fraction operator+(Fraction const &f){

		int lcm = this -> denominator * f.denominator;
		int num1 = (lcm / this -> denominator) * (this -> numerator);
		int num2 = (lcm / f.denominator) * (f.numerator);

		int newNum = num1 + num2;
		int newDen = lcm;

		Fraction Ans(newNum, newDen);

		Ans.Simplify();

		return Ans;
	}

	Fraction operator-(Fraction const &f){


		int lcm = this -> denominator * f.denominator;
		int num1 = (lcm / this -> denominator) * (this -> numerator);
		int num2 = (lcm / f.denominator) * (f.numerator);

		int newNum = num1 - num2;
		int newDen = lcm;	

		Fraction Ans(newNum, newDen);

		Ans.Simplify();
		
		return Ans;	
	}

	Fraction operator*(Fraction const &f){


		int newNum = this -> numerator * f.numerator;
		int newDen = this -> denominator * f.denominator;

		Fraction Ans(newNum, newDen);

		Ans.Simplify();

		return Ans;
	}

	// Pre-Increment Operator
	Fraction& operator++(){

		this -> numerator = (this -> numerator) + (this -> denominator);
		this -> denominator = this -> denominator;

		Simplify();

		return *this;

	}

	
	// Post-Increment Operator
	Fraction operator++(int){


		Fraction Ans(this -> numerator, this -> denominator);	
			
		this -> numerator = (this -> numerator) + (this -> denominator);
		this -> denominator = this -> denominator;

		return Ans;
	}


	Fraction& operator+= (Fraction const &f){



		int lcm = this -> denominator * f.denominator;
		int num1 = (lcm / this -> denominator) * (this -> numerator);
		int num2 = (lcm / f.denominator) * (f.numerator);

		int newNum = num1 + num2;
		int newDen = lcm;

		this -> numerator = newNum;
		this -> denominator = newDen;

		Simplify();	
		
		return *this;	
	}

	void Print(){


		cout << endl << this -> numerator << "/" << denominator << endl;
	}
};