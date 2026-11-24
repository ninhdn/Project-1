#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005; 
int n, a[MAXN];
int st[20][MAXN], sd[20][MAXN];
long long sum = 0; 
int maxx = INT_MIN, minn = INT_MAX;
string s;

void build_sparse_table()
{

    for (int i = 1; i <= n; i++)
    {
        st[0][i] = a[i];
        sd[0][i] = a[i];
    }

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            sd[j][i] = max(sd[j - 1][i], sd[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int query_max(int l, int r)
{
    int m = r - l + 1;
    int k = __lg(m); 
    return max(sd[k][l], sd[k][r - (1 << k) + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
        sum += a[i];
    }

    build_sparse_table();
    cin>>s;
    while (cin >> s)
    {
        if (s == "***") break;
        else if (s == "find-max") cout << maxx << '\n';
        else if (s == "find-min") cout << minn << '\n';
        else if (s == "sum") cout << sum << '\n';
        else 
        {
            int l, r;
            cin >> l >> r;
            cout << query_max(l, r) << '\n';
        }
    }

    return 0;
}