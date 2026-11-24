#include <bits/stdc++.h>
using namespace std;

int n,m;
string z;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    while(n--)
    {
        ans = 0;
        cin>>z;
        int k = z.length();
        for(int i=0;i<k;i++)
        {
            int x = z[i] - 'a' + 'a';
            ans = (ans * 256 + x)%m;    // su dung luoc do horner
        }
        cout<<ans<<'\n';
    }
    return 0;
}