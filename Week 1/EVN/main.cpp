#include <bits/stdc++.h>
using namespace std;

int Giatiencu[10] = {1728,1786,2074,2612,2919,3015};
int Giatienmoi[10] = {1728,2074,2612,3111,3457};
int mocTienCu[10] = {50,50,100,100,100};
int mocTienMoi[10] = {100,100,200,300};
int n;
double Tinhtiencu(int m)
{
    double ans = 0;
    bool check = true;
    int cnt = 0;
    while(check == true)
    {
        if(m>mocTienCu[cnt] && cnt <=4)
        {
            ans += mocTienCu[cnt] * Giatiencu[cnt];
            m -= mocTienCu[cnt];
            cnt++;
        }
        else if(cnt==5 && m > 0)
        {
            ans += m * Giatiencu[cnt];
            check = false;
        } 
        else
        {
            ans += m * Giatiencu[cnt];
            check = false;
        }
    }
    ans = ans * 1.1;
    return ans;
}
double Tinhtienmoi(int m)
{
    double ans = 0;
    bool check = true;
    int cnt = 0;
    while(check == true)
    {
        if(m>mocTienMoi[cnt] && cnt <=3)
        {
            ans += mocTienMoi[cnt] * Giatienmoi[cnt];
            m -= mocTienMoi[cnt];
            cnt++;
        }
        else if(cnt==4 && m > 0)
        {
            ans += m * Giatienmoi[cnt];
            check = false;
        } 
        else
        {
            ans += m * Giatienmoi[cnt];
            check = false;
        }
    }
    ans = ans * 1.1;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cout<<fixed<<setprecision(2)<<Tinhtiencu(n)<<'\n'<<Tinhtienmoi(n)<<'\n';
    cout<<fixed<<setprecision(2)<<Tinhtienmoi(n)-Tinhtiencu(n)<<'\n';
    return 0;
}