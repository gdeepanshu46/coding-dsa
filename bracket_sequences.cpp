#include <bits/stdc++.h>
using namespace std;

void balance(string &s){
	int flag = 1;
	while(flag){
		int zeros = 0, ones = 0;
		int i;
		for(i=0; i<s.size(); i++){
			if(s[i] == '0')
				zeros ++;
			else 
				ones ++;
			if(zeros < ones){
				s = s.substr(i+1) + s.substr(0, i+1);
				break;
			}

		}
		if(i == s.size())
			break;
	}
	
}

int shifts(string &s){
	stack<char> st;
	st.push(s[0]);

	int count = 0;
	for(int i=1; i<s.size(); i++){
		if(s[i] == '(')
			st.push(s[i]);
		else
		{
			if(st.top() == '('){
				st.pop();
				if(st.empty())
					count ++ ;
			}
		}
	}
	return count;
}

int main(){

	string s; 
	cin>> s;

	/* Replace '(' with 0 and ')' with 1 
		and count zeros and ones */
	int zeros = 0, ones = 0;
	for(int i=0; i<s.size();i++){
		if(s[i] == '('){
			s[i] = '0';
			zeros++ ;
		}
		else{
			s[i] = '1';
			ones++ ;
		}
	}


	/* if 0's is equal to 1's bring 
		the balanced string */
	if(zeros == ones)
		balance(s);

	/* if 0's is not equal to 1's string
		can never be balanced */
	else{
		cout << 0 ;
		return 0;
	}
	
	/*Revert string back to its original form */
	for(int i=0; i<s.size();i++){
		s[i] == '0'? s[i] = '(' : s[i] = ')';
	}

	/*all separate sub-balanced strings inside the main string 
		is our total shift 
	For Example : ()()() => 3 separate sub-balanced strings (), () and ()
				(()())() => 2 separate sub-balanced strings (()()) and () */
	cout << shifts(s);
	return 0;
}