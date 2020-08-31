#include <bits/stdc++.h>
using namespace std;

int main(){

	//suffix f after value, or the compiler will take it as double
	float f = 2.15f;
	//float values can have a max precision of 7 digits

	//always prefer to use double in place of float, unless especifically needed
	double d = 21.52;
	//double values can have a max precision of 15 digits

	//by default, cout prints double with the precision of 6 digits
	cout << d << endl; // prints 21.52

	//set precision manually 
	cout << setprecision(15);
	//it will set precision for every double in this program to be 15

	//it will also append trailing zeros and make the double decimal nos to hold 15 places
	cout << fixed << setprecision(15);

	//converting double to string only converts it till 6 digit precision

	//However we can use stringstream for achieving more precision
	stringstream stream;

	stream << fixed << setprecision(9) << d;

	cout << stream.str();

	return 0;
}