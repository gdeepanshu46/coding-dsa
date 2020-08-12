#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, int h){
	if(l >= h){
		cout << s << endl;
		return;
	}

	for(int i=l; i<=h; i++){
		swap(s[i], s[l]);
		permute(s, l+1, h);
		swap(s[i], s[l]);
	}

}

int main(){

	string s = "abc";
	permute(s, 0, s.size()-1);

	return 0;
}