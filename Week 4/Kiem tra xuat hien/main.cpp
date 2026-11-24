#include <bits/stdc++.h>
using namespace std;
int n,a[100001];
map <long long,long long> dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x ; cin >> x;
        if(dem[x]>0)
        {
            cout<<"1"<<'\n';
        }
        else cout<<"0"<<'\n';
        dem[x]++;
    }
    return 0;
}