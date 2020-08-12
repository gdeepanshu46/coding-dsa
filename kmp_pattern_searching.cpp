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

bool is_found(string txt,string pat)
{
    vector<int> v = lps_array(pat);
     int txt_n = txt.size();
    int pat_n = pat.size();
        int i=0;
        int j=0;
        while(i < txt_n && j < pat_n){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }else{
                if(j!=0){
                    j = v[j-1];
                }else{
                    i++;
                }
            }
        }
        if(j == pat_n){
            return true;
        }
        return false;
}
int main()
{
   string txt,pat;
   cin>>txt>>pat;
    cout<<is_found(txt,pat);
	return 0;
}
