#include<bits/stdc++.h>
using namespace std;

string nprimedigit(int number)
{
    int rem;
    string s;

    while(number)
    {
        rem = number % 4;
        switch(rem)
        {
            case 1:
            {
                s.push_back('2');
                break;
            }
            case 2:
            {
                s.push_back('3');
                break;
            }
            case 3:
            {
                s.push_back('5');
                break;
            }
            case 0:
            {
                s.push_back('7');
                number -= 1;
                break;
            }
        }

        number /= 4;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    int number;cin>>number;
    cout<<nprimedigit(number)<<"\n";
    return 0;
}
