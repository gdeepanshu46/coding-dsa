#include<bits/stdc++.h>
using namespace std;

int binary_s(int arr[],int left,int right,int x)
{
    if(left>right)
        return -1;
    int mid = (left+right)/2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid]>x)
        return binary_s(arr,left,mid-1,x);
    else
        return binary_s(arr,mid+1,right,x);
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int index = binary_s(arr,0,9,11);
    cout<<index;
    return 0;
}
