#include<bits/stdc++.h>
using namespace std;

vector<int> lps_array(string s)
{
    int n= s.size();
    vector<int> v(n);
    v[0]=0;
    int i=1,j=0;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            v[i]=j+1;
            i++;j++;
        }
        else
        {
            if(j==0)
            {
                v[i]=0;
                i++;
            }
            else
            {
                j=v[j-1];
            }
        }
    }
    return v;

}
int main()
{
   string s;
   cin>>s;

   vector<int> v = lps_array(s);
    for(auto x:s)
        cout<<x<<" ";
    cout<<endl;
    for(auto x:v)
        cout<<x<<" ";
	return 0;
}
