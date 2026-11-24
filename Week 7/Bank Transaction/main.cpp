#include <bits/stdc++.h>
using namespace std;

string z;
const int max_time = 86400;
struct Transaction
{
    string from,to;
};
unordered_map <string , long long> account_cnt; //so lan chuyen tien theo account
unordered_map <string , long long> cuaccount_cnt; //doanh thu Shop ban cho Customer
string From_Account,To_Account,TimePoint,atm;
vector <string> account;
vector <Transaction> transactions;
int Money;
int rev_to_sec[max_time + 1];
int total_rev[max_time + 1];
int TimeToSecond(const string& t)
{
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long number_transactions = 0;
    long long total_money_transaction = 0;

    while(cin>>From_Account)
    {
        if(From_Account=="#") break;
        cin>>To_Account>>Money>>TimePoint>>atm;
        total_money_transaction += Money ;
        number_transactions ++;

        account_cnt[From_Account] += Money;
        account.push_back(From_Account);
        account.push_back(To_Account);
        transactions.push_back({From_Account,To_Account});
        
    }

    sort(account.begin(), account.end());
    account.erase(unique(account.begin(), account.end()), account.end());
    int n = account.size();
    
    unordered_map<string, int> acc_to_id;
    acc_to_id.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        acc_to_id[account[i]] = i;
    }
    vector<long long> money_from(n, 0);
    vector<vector<int>> adj(n);
    for (const auto& tx : transactions) {
        int u = acc_to_id[tx.from];
        int v = acc_to_id[tx.to];
       
        if (u != v) { // Chu trình gồm các đỉnh phân biệt nên bỏ qua tự chuyển cho chính mình
            adj[u].push_back(v);
        }
    }
    // Loại bỏ các cạnh trùng nhau trong danh sách kề
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    // Mảng đánh dấu đỉnh đã thăm cho DFS
    vector<bool> visited(n, false);
    // Hàm DFS tìm chu trình độ dài k
    auto dfs = [&](auto& self, int u, int start, int depth, int k) -> bool {
        if (depth == k) {
            // Do adj[u] đã được sort, có thể dùng binary_search để kiểm tra cạnh u -> start
            return binary_search(adj[u].begin(), adj[u].end(), start);
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (self(self, v, start, depth + 1, k)) {
                    visited[v] = false;
                    return true;
                }
                visited[v] = false;
            }
        }
        return false;
    };

    while (cin>>z)
    {
        if(z=="#") return 0;
        else 
        {
            if(z == "?number_transactions")
            {
                cout<<number_transactions<<'\n';
            }
            else if(z == "?total_money_transaction")
            {
                cout<<total_money_transaction<<'\n';
            }
            else if(z == "?list_sorted_accounts")
            {
                for(auto v:account) cout<<v<<' ';
                cout<<'\n';
            }
            else if(z == "?total_money_transaction_from")
            {
                cin>>From_Account;
                cout<<account_cnt[From_Account]<<'\n';
            }
            else 
            {
               cin>>From_Account; int k; cin>>k;
               auto it = acc_to_id.find(From_Account);
                if (it == acc_to_id.end() || k < 2) {
                    cout << 0 << "\n";
                } else {
                    int start = it->second;
                    visited[start] = true;
                    bool found = dfs(dfs, start, start, 1, k);
                    visited[start] = false;
                    cout << (found ? 1 : 0) << "\n";
                }
            }
        }
    }
    return 0;
    
}