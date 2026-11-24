#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
string z;
bool check = true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>z;
    int l = z.length();
    if(z[0]=='+') 
    {
        cout<<"NOT_CORRECT"<<'\n';
        return 0;
    }
    long long sum = 0, res = 0;
    for(int i=0;i<l;i++)
    {
        //cout<<z[i]<<' ';
        if(z[i]!='+')
        {
           int k = z[i] - '0';
           sum = sum*10 + k;
           sum = sum%mod;
        }
        else if(z[i]==' ') 
        {
            sum = sum;
            res = res;
        }
        else 
        {
            res = res + sum;
            res = res % mod;
            sum = 0;
        }
    }
    if(sum==0) 
    {
        cout<<"NOT_CORRECT"<<'\n';
        return 0;
    }
    else 
    {
        res = res + (sum%mod);
        res = res % mod;
        cout<<res<<'\n';
        return 0;
    }
    return 0;
}