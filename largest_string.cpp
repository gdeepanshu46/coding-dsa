#include <bits/stdc++.h>
using namespace std;

 
bool comp(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    if(s1.size() > s2.size()){
        swap(s1, s2);
    }
    
    for(int i=0; i<s1.size(); i++){
        
        if(s1[i] == s2[i]){
            continue;
        }
        if(s1[i] > s2[i]){
            // cout << "1";
            return true;
        }
        else{
            // cout << "2";
            return false;
        }
    }

    if(s1.size() == s2.size()){
        //cout << "3";
        return true;
    }


    if(s1[0] > s2[s1.size()])
    {
        //cout << "4";
        return true;
    }
    else {
        //cout << "5" << endl;
        return false;
    }
}

string findLargestNumber(vector<int> A)
{
    
    // return "";
     string temp;
    sort(A.begin(), A.end(), greater<int>());
    
    sort(A.begin(), A.end(), comp);
    
     for(auto x : A){

         temp += to_string(x);
     }



    return temp;
}

int main(){

	int a = 23;
    string temp = to_string(a);

    cout << temp ;

    string str = "";

    str += temp; 

    cout << str;
    O



	return 0;
}
