#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void add_edge(vector<vector<int>> &vec,int u,int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}
void print_graph(vector<vector<int>> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        for(auto x : vec[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void dfs(vector<vector<int>> vec,int source,vector<int> &temp)
{
    if(temp[source]==0)
    {
        cout<<source<<" ";
        temp[source]=-1;
        for(int i=0;i<vec[source].size();i++)
        {
            dfs(vec,vec[source][i],temp);
        }
    }
}
void bfs(vector<vector<int>> vec,int source)
{
    vector<int> temp(vec.size());
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int get = q.front();
        cout<<get<<" ";
        temp[get]=-1;
        q.pop();
        for(int i=0;i<vec[get].size();i++)
        {
            if(temp[vec[get][i]]==0)
            {
                q.push(vec[get][i]);
                temp[vec[get][i]]=-1;
            }

        }
    }

}
bool detect_cycle_undirected(vector<vector<int>> vec,int source)
{
    vector<int> temp(vec.size());
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int get = q.front();
        //cout<<get<<" ";
        temp[get]=-1;
        q.pop();
        for(int i=0;i<vec[get].size();i++)
        {
            if(temp[vec[get][i]]==0)
            {
                q.push(vec[get][i]);
                temp[vec[get][i]]=-1;
            }
            else
            {
                if(vec[get][i]!=get)
                    return true;
            }

        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 3;
    vector<vector<int>> vec(n);
    vector<int> temp(n);
    add_edge(vec,0,1);
    add_edge(vec,0,2);
    //add_edge(vec,1,2);
//    add_edge(vec,1,4);
//    add_edge(vec,2,3);
//    add_edge(vec,4,5);
    print_graph(vec);
    cout<<endl;
    //bfs(vec,0);
    dfs(vec,0,temp);
    cout<<endl;
    cout<<detect_cycle_undirected(vec,0);



    return 0;
}

