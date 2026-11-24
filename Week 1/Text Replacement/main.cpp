#include <bits/stdc++.h>
using namespace std;
string text,p1,p2;

void ReplaceAll(string &text,const string &from,const string &to)
{
    if(from.empty()) return;
    size_t pos = 0;
    while((pos = text.find(from,pos)) != string::npos)
    {
        text.replace(pos,from.length(),to);
        pos += to.length();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,p1);
    getline(cin,p2);
    getline(cin,text);
    ReplaceAll(text,p1,p2);
    cout<<text<<'\n';
    return 0;
}