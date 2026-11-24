#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000001],maxx[1000001];
int minn[1000001];
int ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    maxx[0] = INT_MIN , minn[0] = INT_MAX;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        maxx[i] = max(maxx[i-1],a[i]);
        minn[i] = min(minn[i-1],a[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i] + maxx[i] < m) continue;
        else if(a[i] + minn[i] > m) continue;
        else 
        {
            for(int j=i-1;j>=1;j--) 
            {
                if(a[i]+a[j]==m)
                {
                    ans++; break;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}