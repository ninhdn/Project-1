#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[100001];
bool check[100001];

void BFS(int u)
{
    queue <int> q;
    q.push(u);
    check[u] = false;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout<<v<<' ';
        for(auto x:adj[v])
        {
            if(check[x]==true)
            {
                q.push(x);
                check[x] = false;
            }
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
    for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
    memset(check,true,sizeof(check));
    for(int i=1;i<=n;i++)
    {
        if(check[i]) BFS(i);
    }
    return 0;
}
