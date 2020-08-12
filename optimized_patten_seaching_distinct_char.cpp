//return index of matched string or -1 else
#include<bits/stdc++.h>
using namespace std;
int pattern_searching(string txt,string pat)
{
    int txt_size = txt.size();
    int pat_size = pat.size();
    int i,j;
    for(i=0;i<=txt_size-pat_size;)
    {
        for(j=0;j<pat_size;j++)
        {
            if(txt[i+j]!=pat[j])
            {
                break;
            }
        }
        if(j==pat_size)
            return i;
        if(j==0)
            i++;
        else
            i=i+j;

    }
    return -1;
}

int main()
{
     string txt,pat;
     cin>>txt>>pat;
     cout<<pattern_searching(txt,pat);

	return 0;
}

