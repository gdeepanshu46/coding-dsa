#include <bits/stdc++.h>
using namespace std;

enum month
{
	January = 1, February, March, April, May, June, July, 
	August, September, October, November, December
};

int main(){

	cout << January << endl;
	
	map<string, int> mp_month;

	mp_month.insert({"January", 1});
	mp_month.insert({"February", 2});
	mp_month.insert({"March", 3});
	mp_month.insert({"April", 4});
	mp_month.insert({"May", 5});
	mp_month.insert({"June", 6});
	mp_month.insert({"July", 7});
	mp_month.insert({"August", 8});
	mp_month.insert({"September", 9});
	mp_month.insert({"October", 10});
	mp_month.insert({"November", 11});
	mp_month.insert({"December", 12});


	

	return 0;
}