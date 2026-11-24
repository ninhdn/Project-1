#include <bits/stdc++.h>
using namespace std;
int n,a[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    a[0] = 0;
    a[1] = 1;
    for(int i=2;i<=n;i++) a[i] = a[i-1] + a[i-2];
    cout<<a[n-1]<<'\n';
    return 0;
}