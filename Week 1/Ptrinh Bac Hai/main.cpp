#include <bits/stdc++.h>
using namespace std;

int a,b,c;
double ans1,ans2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c;
    double delta = b*b - 4*a*c;
    if(delta>0)
    {
        ans1 = ( -b + sqrt(delta) )/ (2*a);
        ans2 = ( -b - sqrt(delta) )/ (2*a);
        cout<<fixed<<setprecision(2)<<ans2<<' '<<ans1<<'\n';
    }
    else if(delta == 0)
    {
        ans1 = -b/(2*a);
        cout<<fixed<<setprecision(2)<<ans1<<'\n';
    }
    else 
    {
        cout<<"NO SOLUTION"<<'\n';
    }
    return 0;
}