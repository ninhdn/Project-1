#include <bits/stdc++.h>
using namespace std;

int n, a[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        a[i] = a[i-1] + k;
    }
    int Q; cin>>Q;
    while(Q--)
    {
        int i1,j1,i2,j2;
        cin>>i1>>j1>>i2>>j2;
        int k1 = a[j1] - a[i1-1];
        int k2 = a[j2] - a[i2-1];
        if(k1 < k2) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}