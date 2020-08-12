#include <bits/stdc++.h>
using namespace std;

int countt;
void permute(vector<int> v, int l, int h){
	if(l >= h){
		if(countt != 5){
			countt ++ ;
			return ;
		}
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	for(int i=l; i<=h; i++){
		swap(v[i], v[l]);
		permute(v, l+1, h);
		swap(v[i], v[l]);
	}

}

int main(){

	vector<int> v{1, 2, 3};

	permute(v, 0, v.size()-1);

	return 0;
}