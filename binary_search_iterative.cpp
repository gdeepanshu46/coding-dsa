#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int binary_s(int arr[],int low,int high,int x)
{

    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            high = mid-1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]={1,2,3,4,5,6,7,8,9,10};
    cout<<binary_s(arr,0,9,13);


    return 0;
}

