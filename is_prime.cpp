//According to Fundamental Theorem of Arithmetic, every positive whole number can be
//written as the unique product of primes. This is the reason why 1 is not a prime no.
//15 = 5*3 correct
//15 = 1*5*3 or 1*1*5*3 violates the Theorem

#include <bits/stdc++.h>
using namespace std;

//Time : O(sqrt(n))
bool isPrime(int n){
	if(n == 0 || n == 1) return 0;

	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0) return 0;
	}

	return 1;
}

//Every prime no can be expressed in the form of 6*n + 1 or 6*n - 1 except 2 and 3
//But not every no that can be expressed in this form is a prime
//this method can be only used to weed out some possibilities
//Time : O(1)
bool isPrime_(long long n){
	if(n <= 1) return 0;

	if(n <= 3) return 1;

	int left = n-1;
	int right = n+1;

	if(left%6 == 0 || right%6 == 0) return 1;

	return 0;
}

int main(){

	int t; cin>>t;
	while(t--){
		
		long long n; cin>>n;

		cout << isPrime_(n) << endl;
	}
	return 0;
}