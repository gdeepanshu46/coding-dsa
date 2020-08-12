#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void countSmallerBinary(int n) {
    int res[n] = {0};
    for (int i=0; i<n; i++)
      cout<<res[i]<<" ";
    cout<<endl;

}
int main()
{
    int arr[] = {1,2,3,4,5};
    cout<<arr<<" "<<&arr[0]<<" "<<&arr;

    return 0;
}


