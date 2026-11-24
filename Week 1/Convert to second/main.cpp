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
        if(s[i] == ':')
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
                if(z.length()!=2)
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
    if(cnt!=3 || mang[1]< 0 || mang[1]>=24) 
    {
        cout<<"INCORRECT"<<'\n';
        return 0;
    }
    else if(mang[2]<0 || mang[2]>=60 || mang[3]<0 || mang[3] >=60)
    {
        cout<<"INCORRECT"<<'\n';
        return 0;
    }
    else 
    {
        int ans = mang[1]*3600 + mang[2]*60 + mang[3];
        cout<<ans<<'\n';
        return 0;
    }
}