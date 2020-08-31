#include<bits/stdc++.h>
using namespace std;

int countDigitK(int item,int k)
{
    int count=0;
    while(item>0)
    {
        if(item%10 == k)
            count++;
        item/=10;
    }
    return count;
}
int NumWithMaxK(int k,int arr[],int n)
{
    if(arr == NULL)
        return -1;
    if(n == 0)
        return 0;

    int ans=0,tempCount,elmt=INT_MIN;
    for(auto i=0;i<n;i++)
    {
        tempCount = countDigitK(arr[i],k);
        if(tempCount >= ans)
        {
            ans = tempCount;
            elmt = max(elmt,arr[i]);
        }
    }
    if(!ans)
        return 0;
    else
        return elmt;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n; cin>>n;
        int arr[n];
        for(auto i=0;i<n;i++) cin>>arr[i];
        int k; cin>>k;
        cout<<NumWithMaxK(k,arr,n)<<"\n";
    }
    return 0;
}