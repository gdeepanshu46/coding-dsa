#include<bits/stdc++.h>
using namespace std;

int mid_index(int ss,int se)
{
    return (ss + (se-ss)/2);
}
void st_construction_util(vector<int> v,vector<int> &st,int ss,int se,int si)
{
    if(ss==se)
    {
        st[si]=v[ss];
        return;
    }
    int mid=mid_index(ss,se);
    st_construction_util(v,st,ss,mid,2*si+1);
    st_construction_util(v,st,mid+1,se,2*si+2);
    st[si] = st[2*si+1] + st[2*si+2];
}
vector<int> st_construction(vector<int> v)
{
    int n=v.size();
    int h = ceil(log2(n));
    int max_size = 2*pow(2,h)-1;


    vector<int> st(max_size);
    st_construction_util(v,st,0,n-1,0);
    return st;
}
int range_addition_util(vector<int> st,int ss,int se,int l,int h,int si)
{
    if(l<=ss && h>=se)
        return st[si];
    else if(l>se || h<ss)
        return 0;
    else
    {
        int mid = mid_index(ss,se);
        return range_addition_util(st,ss,mid,l,h,si*2+1) + range_addition_util(st,mid+1,se,l,h,si*2+2);
    }
}
int range_addition_query(vector<int> st,int n,int l,int r)
{

    return range_addition_util(st,0,n-1,l,r,0);
}
void updation_util(vector<int> &st,int ss,int se,int si,int i,int diff)
{
    if(i<ss || i>se)
        return ;
    st[si]+=diff;
    if(ss!=se)
    {
        int mid = mid_index(ss,se);
        updation_util(st,ss,mid,si*2+1,i,diff);
        updation_util(st,mid+1,se,si*2+2,i,diff);
    }
}
void updation_query(vector<int> &v,vector<int> &st,int i,int x)
{
    int n = v.size();
    int diff = x-v[i];
    v[i]=x;
    updation_util(st,0,n-1,0,i,diff);

}

int main()
{
    vector<int> v = {1,2,3,4};
    int n = v.size();
    vector<int> st = st_construction(v);
    for(auto x:v)
        cout<<x<<" " ;
    cout<<endl;
    cout<<range_addition_query(st,n,1,3);
    cout<<endl;
    updation_query(v,st,2,10);
    cout<<range_addition_query(st,n,1,3);
    cout<<endl;
    for(auto x:v)
        cout<<x<<" " ;
	return 0;
}
