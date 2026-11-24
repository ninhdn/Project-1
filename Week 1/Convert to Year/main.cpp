#include <bits/stdc++.h>
using namespace std;

string s,z;
int mang[4],cnt = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int L = s.length();
    for(int i=0;i<L;i++)
    {
        if(s[i] == '-')
        {
            if(z[0]==' ')
            {
                if(z.length()!=3)
                {
                    cout<<"INCORRECT"<<'\n';
                    return 0;
                }
            }
            else 
            {
                if(z.length()!=4)
                {
                    cout<<"INCORRECT"<<'\n';
                    return 0;
                }
            }
            mang[++cnt] = stoi(z);
            z = ' ';
            continue;
        }
        else
        {
            z += s[i];
        }
    }
    if(z.length()!=3)
    {
        cout<<"INCORRECT"<<'\n';
        return 0;
    }
    mang[++cnt] = stoi(z);
   // cout<<cnt<<' ';
    //for(int i=1;i<=cnt;i++) cout<<mang[i]<<' ';
    if(cnt!=3) 
    {
        cout<<"INCORRECT"<<'\n';
        return 0;
    }
    else if(mang[2]<0 || mang[2]>=13 || mang[3]<0 || mang[3] >=31)
    {
        cout<<"INCORRECT"<<'\n';
        return 0;
    }
    else 
    {
        cout<<mang[1]<<' '<<mang[2]<<' '<<mang[3]<<'\n';
    }
    return 0;
}