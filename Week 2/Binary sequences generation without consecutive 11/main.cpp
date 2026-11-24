#include <bits/stdc++.h>
using namespace std;

int n,a[100];
void print()
{
    bool check = true;
    for(int j=2;j<=n;j++) 
    {
        if(a[j]==1 && a[j-1]==1) 
        {
            check = false;
            break;
        }
    }
    if(check==true)
    {
        for(int j=1;j<=n;j++) cout<<a[j];
        cout<<'\n';
    }
}
void backtrack(int m)
{
    for(int i=0;i<=1;i++)
    {
        a[m] = i;
        if(m==n) 
        {
            print();
        }
        else backtrack(m+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    backtrack(1);
    return 0;
}