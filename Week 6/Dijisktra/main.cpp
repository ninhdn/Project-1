#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; 
struct Edge {
    int to;
    int weight;
};

int main() {
    // Tối ưu tốc độ nhập/xuất (Fast I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Danh sách kề biểu diễn đồ thị có hướng
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Mảng khoảng cách cho 1 lượt Dijkstra
    vector<long long> dist(n + 1);
    fill(dist.begin(), dist.end(), INF);
    int s , t; cin>>s>>t;
    dist[s] = 0; // Khoảng cách từ đỉnh tới chính nó bằng 0

    // Hàng đợi ưu tiên lưu cặp (khoảng cách, đỉnh), sắp xếp khoảng cách tăng dần
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;
        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[t] == INF) 
    {
        cout << -1;
    } 
    else 
    {
        cout << dist[t];
    }
  
    return 0;
}