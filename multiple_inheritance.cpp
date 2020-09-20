//class C inherits both the show() functns from class A and class B
//and when the object of C calls show(), it becomes ambiguous, which one to call
//it can be resolved by using :
//1. scope resolution operator (::)
//2. By defining our own show() in derived class.

//In java, we don't use multiple inheritance using classes to avoid this diamond problem
//we achieve multiple inheritance using Interfaces, because it contains abstract methods,
//so it becomes compulsory to define each and every method in the derived classes.

#include <bits/stdc++.h>
using namespace std;

class A{
public:
	void show(){ cout << "A class"; }

};

class B{
public:
	void show(){ cout << "B class"; }
};


class C : public A, public B{
public:
	// void show(){ cout << "C class"; }
};



int main(){

	C obj;

	obj.B::show();

	return 0;
}