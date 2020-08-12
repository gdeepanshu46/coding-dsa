#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

class hasharray
{
	vector<int> vec;
	unordered_map<int, int> um;
	
public:	
	void insert__(int n){
		vec.push_back(n);
		um[n] = vec.size();
	}

	bool search(int n){
		if(um[n])
			return 1;
		else
			return 0;
	}

	void delete_(int n){
		if(!um[n]){
			cout<<"Element not present"<<endl;
			return;
		}
		swap(vec[um[n]-1], vec[vec.size()-1]);
		um[vec[um[n]-1]] = um[n];
		um[n] = 0;
		vec.pop_back();
	}

	void display_(){
		for(auto x: vec){
			cout<<x<<" ";
		}
		cout<<endl;
	}

};
int main()
{
	hasharray h1;
	h1.insert__(1);
	h1.insert__(2);
	h1.insert__(3);
	h1.insert__(4);
	h1.insert__(5);
	h1.insert__(6);
	h1.display_();
	cout<<h1.search(3);
	h1.delete_(2);
	cout<<endl;
	h1.display_();
	h1.delete_(22);
	cout<<endl;
	h1.display_();



	return 0;
}

