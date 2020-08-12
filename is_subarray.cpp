#include <bits/stdc++.h>
using namespace std;

	bool isSubArray(vector<int> v1, vector<int> v2){
		if(v1.size() < v2.size()){
			swap(v1, v2);
		}

		int n1 = v1.size();
		int n2 = v2.size();

		int i=0, j=0; 
		int parent = 0;

		while(i < n1 && j < n2){
			if(v1[i] == v2[j]){
				parent = i;
				i++;
				j++;
			}
			else{
				i=parent+1;
				parent=i;
				j=0;
			}
		}
		if(j == n2)
			return true;
		else
			return false;
	}

int main(){

	vector<int> v1{1, 2, 3, 4, 5};
	vector<int> v2{5};

	cout << isSubArray(v1, v2) << endl;
	


	return 0;
}