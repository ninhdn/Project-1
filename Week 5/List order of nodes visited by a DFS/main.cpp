#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[100001];
bool check[100001];
void DFS(int u)
{
    cout<<u<<' ';
    check[u] = false;
    for(auto v:adj[u])
    {
        if(check[v]==true) 
        {
            DFS(v);
            //check[v] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(check,true,sizeof(check));
    DFS(1);
    return 0;
}
