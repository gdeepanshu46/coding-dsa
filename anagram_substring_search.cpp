#include<bits/stdc++.h>
using namespace std;
bool check(int txt[],int pat[])
{
    for(int i=0;i<256;i++)
    {
        if(txt[i]!=pat[i])
            return false;
    }
    return true;
}
int anagram(string txt,string pat)
{
    int c=0;
    int count_txt[256]={0};
    int count_pat[256]={0};
    for(int i=0;i<pat.size();i++)
    {
        count_txt[txt[i]]++;
        count_pat[pat[i]]++;
    }
    for(int i=pat.size();i<txt.size();i++)
    {
        if(check(count_txt,count_pat))
            c++;
        count_txt[txt[i]]++;
        count_txt[txt[i-pat.size()]]--;

    }
    if(check(count_txt,count_pat))
            c++;
    return c;
}
int main()
 {
     int t;cin>>t;
     while(t--)
     {
         string txt,pat;cin>>txt>>pat;
         cout<<anagram(txt,pat)<<"\n";

     }

	return 0;
}
