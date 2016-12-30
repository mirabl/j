/*
https://community.topcoder.com/stat?c=problem_statement&pm=3970&rd=7993

0)
6800
100
68
Returns: 1.3322616182218813E-13
Noting that 68 payments of 100 equals the total price of 6800, so there is no interest.
1)
2000
510
4
Returns: 9.56205462458368
Here, we do pay a little interest. At 9.562% annual interest, that means each month we pay 0.7968% of the balance in interest. Our payment schedule looks like this:
Month | + Interest | - Payment | = Balance
------------------------------------------
      |            |           |  2000.00
   1  |     15.94  |   510.00  |  1505.94
   2  |     12.00  |   510.00  |  1007.94
   3  |      8.03  |   510.00  |   505.97
   4  |      4.03  |   510.00  |     0.00
2)
15000
364
48
Returns: 7.687856394581649
This is similar to what purchasing a new car with no money down might look like, if you make payments for 4 years.

Constraints
- price will be between 1 and 1000000, inclusive.
- monthlyPayment will be between 0 and price / 2, inclusive.
- loanTerm will be between 1 and 600, inclusive.
- The resulting interest rate will be between 0 and 100, inclusive.

*/
#include <iostream>

using namespace std;

class AutoLoan {
public:
	double apply(double price, double monthlyPayment, int loanTerm, double yearlyRate) {
		double x = price;
		for (int i = 0; i < loanTerm; ++i) {
			x = (x * (1 + yearlyRate / 12.0)) - monthlyPayment;
		}
		return x;
	}

	double interestRate(double price, double monthlyPayment, int loanTerm) {
		double lo = 0.0;
		double hi = 100.0;
		double pres = 0.0000001; // fixme

		double x = (hi + lo) / 2.0;
		double y = apply(price, monthlyPayment, loanTerm, x);

		while (!(y < pres && y > -pres)) {
			if (y < 0) {
				lo = x;
			} else {
				hi = x;
			}
			x = (hi + lo) / 2.0;
			y = apply(price, monthlyPayment, loanTerm, x);
		}

		return x;
	}
};

int main() {
	AutoLoan x;
	cout << x.interestRate(6800, 100, 68) << " 1.3322616182218813E-13" << endl;
	cout << x.interestRate(2000, 510, 4) << " 9.56205462458368" << endl;
	cout << x.interestRate(15000, 364, 48) << " 7.687856394581649" << endl;
}