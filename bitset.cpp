#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    bitset<8> bs;
    string s = "1001";
    bitset<8> bs2(s);
    cout<<bs2<<endl;
    int total = bs2.size();
    int set_b = bs2.count();
    cout<<"total bits "<<total<<endl;
    cout<<"set bits "<<set_b<<endl;
    cout<<"unset bits "<<total - set_b<<endl;
    cout<<bs2.any()<<endl;
    cout<<bs2.none()<<endl;
    bs2.set(1);
    cout<<bs2<<endl;
    bs2.set();
    cout<<bs2<<endl;
    bs2.reset(2);
    cout<<bs2<<endl;
    bs2.flip();
    cout<<bs2<<endl;
    bs2.reset();
    cout<<bs2<<endl;


    return 0;
}


