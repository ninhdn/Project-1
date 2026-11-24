#include <bits/stdc++.h>
using namespace std;
int n,k,sum[1000000],ans = 0;
int a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
        //cout<<sum[i]<<' ';
    }
    for(int i=1;i<=n-k+1;i++)
    {
        int z = sum[i+k-1] - sum[i-1];
        //cout<<z<<' ';
        if(z%2==0) ans++;
        else continue;
    }
    cout<<ans<<'\n';
    return 0;
}