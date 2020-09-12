#include <bits/stdc++.h>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 
			  31, 31, 30, 31, 30, 31};

bool isLeap(int year){

	return ((year%400 == 0) || (year%4 == 0 && year%100 != 0));
}

int day_no(string s){

	//Extract day, mon and year
	int day = stoi(s.substr(0, 2));
	int month = stoi(s.substr(3, 2));
	int year = stoi(s.substr(6));

	//if month is after feb and the year is leap too, increment day count by 1
	if(month > 2 && isLeap(year)){
		day++;
	}

	//add all days before given month
	int count_days = 0;
	for(int i=0; i<month-1; i++){
		count_days += days[i];
	}

	//finally add current month days
	count_days += day;

	return count_days;
}

int main(){

	string s; cin>>s; //11-03-1999 format

	cout << day_no(s) << endl;

	return 0;
}