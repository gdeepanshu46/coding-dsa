//MultiThreading not implemented yet in this code

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

#define ull unsigned long long

void sumEven(ull start, ull end){
	ull evenSum = 0;

	for(ull i=start; i <= end; i++){
		if(i%2 == 0) evenSum += i;
	}
}

void sumOdd(ull start, ull end){
	ull oddSum = 0;

	for(ull i=start; i <= end; i++){
		if(i%2 == 0) oddSum += i;
	}
}

int main(){

	ull start = 0;
	ull end = 1900000000;

	auto startTime = high_resolution_clock::now();	

	sumEven(start, end);
	sumOdd(start, end);

	auto endTime = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(endTime - startTime);

	cout << "Time : " << duration.count() << endl;

	return 0;
}