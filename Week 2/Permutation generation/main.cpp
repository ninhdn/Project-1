#include <bits/stdc++.h>
using namespace std;
int n,k,a[1001];
bool check[100001];
void print()
{
    for(int i=1;i<=n;i++) 
    {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
void backtrack(int m)
{
    for(int i=1;i<=n;i++)
    {
        if(check[i]==true)
        {
            a[m] = i;
            check[i] = false;
            if(m==n) print();
            else backtrack(m+1);
        }
        else continue;
        check[i] = true;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(check,true,sizeof(check));
    cin>>n;
    backtrack(1);
    return 0;
}