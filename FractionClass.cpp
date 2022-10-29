#include <algorithm>

class Fraction{

	private:

	int numerator;
	int denominator;

	public:

	Fraction(int numerator, int denominator){


		this -> numerator = numerator;
		this -> denominator = denominator;
	}


	void Print(){


		cout << numerator << " / " << denominator << endl;
	}	
	

	void Add(Fraction f){ // Try dynamic allocation


		int lcm = denominator * f.denominator;
		int num1 = (lcm / denominator) * numerator;
		int num2 = (lcm / f.denominator) * f.numerator;

		numerator = num1 + num2;
		denominator = lcm;

		Simplify();
	}

	void Simplify(){
	
		int gcd;
		int minimum = min(numerator, denominator);

		for(int i = 1; i <= minimum; i++){


			if(numerator % i == 0 && denominator % i == 0){


				gcd = i; // Try breaking the loop
			}
		}

		numerator /= gcd;
		denominator /= gcd;
	}
	
};