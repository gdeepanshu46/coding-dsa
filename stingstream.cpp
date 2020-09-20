#include <bits/stdc++.h>
using namespace std;

int main(){

	stringstream sso; //stringstream object creation

	string str;
	getline(cin, str);

	sso << str; //inserting s into our stream object;

	string temp; //temporary string

	while(sso >> temp)  //printing each and every word of the stream 
		cout << temp;


	return 0;
}