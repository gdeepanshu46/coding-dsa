#include <bits/stdc++.h>
using namespace std;

class Person{
	int age;
	string name;

public:

	//making them frnd func, so that they can access private members of Person Class
	friend ostream &operator << (ostream &os, Person &p);
	friend istream &operator >> (istream &is, Person &p);
	friend Person operator + (Person &p1, Person &p2);
};

//Overloading + operator
Person operator + (Person &p1, Person &p2){
	Person p3;
	p3.age = p1.age + p2.age;
	p3.name = p1.name + p2.name;
	return p3;
}



//Overloading stream insertion and extraction operators
//taking objects as reference, to avoid creating copies
ostream &operator << (ostream &os, Person &p){
	os << p.age << " " << p.name << endl;
	return os;
}

istream &operator >> (istream &is, Person &p){
	is >> p.age >> p.name;
	return is;
}



int main(){

	Person p1, p2, p3;

	cin >> p1 >> p2;

	p3 = p1 + p2;

	cout << p3;

	return 0;
}