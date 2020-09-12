#include <bits/stdc++.h>
using namespace std;

//disks stacked up from top to bottom as 1 2 3 4 ..
//Total no of moves = 2^n - 1

void toh_helper(int n, char A, char B, char C){

	//if single disk is present, move to the destination disk
	if(n == 1){
		cout << "Move disk " << n << "-> " << C << endl;
		return;
	}

	//move n - 1 disks to intermediate rod using destination rod
	toh_helper(n-1, A, C, B);

	//move largest rod to destination rod
	cout << "Move disk " << n << "-> " << C << endl;
	
	//move n - 1 disks back to destination rode using current rod
	toh_helper(n-1, B, A, C);
}

void toh(int n){
	char A = 'A', B = 'B', C = 'C';
	toh_helper(n, A, B, C);
}

int main(){

	int n; cin>>n;
	toh(n);

	return 0;
}