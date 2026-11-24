#include <bits/stdc++.h>
using namespace std;

string z;
int CountWord(const string& text)
{
    int cnt = 0;
    bool inWord = false;

    for(auto c:text)
    {
        if(isspace(c))
        {
            if(!inWord)
            {
                inWord = true;
                cnt ++;
            }
        }
        else inWord = false;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getline(cin,z);
    cout<<CountWord(z)<<'\n';
    return 0;
}