#include <bits/stdc++.h>
using namespace std;

map <string,int> dem;
string z;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(cin>>z)
    {
        if(z=="*") break;
        if(dem[z]==0) dem[z]++;
        else continue;
    }
    while(cin>>z)
    {
        if(z=="***") break;
        if(z=="find")
        {
            string x; cin>>x;
            cout<<dem[x]<<'\n';
        }
        else
        {
            string x ; cin>>x;
            if(dem[x]==0)
            {
                cout<<"1"<<'\n';
                dem[x]++;
            }
            else cout<<"0"<<'\n';
        }
    }
    return 0;
}