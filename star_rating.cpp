#include <bits/stdc++.h>
using namespace std;

double star_rating(double num){

	double res = (num/5.0)*100;
	res = res/20.0;

	double floor_ = floor(res);
	double ceil_ = ceil(res);

	if(abs(res - floor(res)) < abs(res - ceil(res))){
		ceil_ = ceil(res) - 0.5;
	}
	else
		floor_ = floor(res) + 0.5;


	if(abs(res - floor_) < abs(res - ceil_)){
		res = floor_;
	}
	else
		res = ceil_;

	return res;
}

void print_string(double num){

	for(int i=0; i<5; i++){
		if(num > 0.5){
			cout << "full ";
			num -= 1.0;
		}
		else if(num == 0.5){
			cout << "half ";
			num -= 0.5;
		}
		else{
			cout << "empty ";
		}
	}
	cout << endl;
}


void StringChallenge(string s){
	double num = stod(s);

	num = star_rating(num);

	print_string(num);

}

int main(){

	string str; cin>>str;
	StringChallenge(str);
	return 0;
}