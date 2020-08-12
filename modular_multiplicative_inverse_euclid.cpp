#include<bits/stdc++.h>
using namespace std;
int d;//, x, y;//include this with the function
void extendedEuclid(int A, int B,int *x,int *y) {
    if(B == 0) {
        d = A;
        *x = 1;
        *y = 0;
    }
    else {
        extendedEuclid(B, A%B,x,y);
        int temp = *x;
        *x = *y;
        *y = temp - (A/B)*(*y);
    }
}

int main( ) {
    int x,y;
extendedEuclid(197,3000,&x,&y);
x=(x+3000)%3000;
cout << "MMI of a is "<< x<< endl;
return 0;
}
