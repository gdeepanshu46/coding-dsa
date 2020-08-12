//return index of matched string or -1 else
#include<bits/stdc++.h>
using namespace std;

bool check_rotation(string txt,string pat)
{
    pat = pat + pat;
    if(pat.find(txt)!=string::npos)
        return true;
    return false;
}

int main()
{
     string txt,pat;
     cin>>txt>>pat;
     cout<<check_rotation(txt,pat);

	return 0;
}


