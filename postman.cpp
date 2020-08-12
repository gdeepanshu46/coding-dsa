#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[10000][10000];
    int x = 0, y = 0;
    for(int i=0; i<10000 ; i++){
        for(int j=0; j<10000; j++){
            arr[i][j] = ' ';
        }
    }
    while(1){
        string s1; 
        string s2;
        cin >> s1;
        if(s1 == "x"){
            break;
        }
        cin >> s2;

        
        

        int n = stoi(s1);

        int i;

        if(s2 == "S"){
            for(i = y; i<= n+y; i++){
                arr[x][i] = '|';
            }
            y = i;

        }
        else if(s2 == "N"){
            for(int i = y; i>= y-n; i--){
                arr[x][i] = '|';
            }
            y = i;


        }
        else if(s2 == "E"){
            for(int i = x; i<= n+x; i++){
                arr[i][y] = '-';
            }
            x = i;
            
        }
        else if(s2 == "W"){
            for(int i = x; i>= x-n; i--){
                arr[i][y] = '-';
            }
            x = i;
            
        }
        else if(s2 == "SW"){
            
        }
        else if(s2 == "SE"){
            
        }
        else if(s2 == "NE"){
            
        }
        else if(s2 == "NW"){
            
        }
         

        

    }

    for(int i=0; i<10000 ; i++){
        for(int j=0; j<10000; j++){
                cout << arr[i][j]<< " ";

        }
        cout << endl;
    }
    return 0;
}