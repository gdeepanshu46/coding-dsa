#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

double median_(vector<int> v1,vector<int> v2)
{
    if(v1.size()>v2.size())
        return median_(v2,v1);
    int x = v1.size();
    int y = v2.size();
    int low = 0;
    int high = x;
    while(low<=high)
    {
        int partitionx = (low+high)/2;
        int partitiony = (x+y+1)/2 - partitionx;
        int maxleftx = (partitionx==0)? INT_MIN : v1[partitionx-1];
        int minrightx = (partitionx==x)? INT_MAX : v1[partitionx];
        int maxlefty = (partitiony==0)? INT_MIN : v2[partitiony-1];
        int minrighty = (partitiony==y)? INT_MAX : v2[partitiony];

        if(maxleftx<=minrighty && maxlefty <= minrightx)
        {
            if((x+y)%2==0)
            {
                return (max(maxleftx,maxlefty)+min(minrightx,minrighty))/2.0;
            }
            else
                return max(maxleftx,maxlefty);
        }
        else if(maxleftx>minrighty)
        {
            high = partitionx-1;
        }
        else
            low = partitionx+1;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1{1,2,3,100};
    vector<int> v2{4,5,200};
    cout<<median_(v1,v2);




    return 0;
}

