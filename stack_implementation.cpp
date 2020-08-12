#include <bits/stdc++.h>
using namespace std;

class stack_
{
	vector<int> v;
	int minEle = 0;

public:
	bool isEmpty(){
		return v.size() == 0;
	}

	void push(int val){

		if(isEmpty()){
			v.push_back(val);
			minEle = val;
			return;
		}

		if(val < minEle){
			v.push_back(2*val - minEle);
			minEle = val;
		}
		else
			v.push_back(val);
	}

	int top(){
		return v[v.size()-1];
	}

	void pop(){
		if(this->top() < minEle){
			minEle = 2*minEle - this->top();
		}

		v.pop_back();
	}

	int getMin(){
		return minEle;
	}
	
};

int main(){

	stack_ s; 
	s.push(10);
	s.push(12);
	s.push(23);

	cout << s.top() << endl;

	cout << s.getMin() << endl;

	s.push(5);

	cout << s.getMin() << endl;

	s.pop();

	cout << s.getMin() << endl;


	return 0;
}