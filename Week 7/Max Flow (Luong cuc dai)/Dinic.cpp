///Thuật toán Dinc (Tối ưu nhất khi tìm luồng cực đại)
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Dinic {
    struct Edge {
        int to;
        long long cap; // Khả năng thông qua tối đa
        long long flow; // Luồng hiện tại
    };

    int n, m , s, t;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> level; // Khoảng cách (tầng) từ đỉnh phát s
    vector<int> ptr;   // Kỹ thuật Current Arc: lưu cạnh đang xét để không duyệt lại cạnh đã đầy

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n + 1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }

    void add_edge(int u, int v, long long cap) {
        // Cạnh xuôi (u -> v) có khả năng thông qua = cap
        adj[u].push_back(edges.size());
        edges.push_back({v, cap, 0});

        // Cạnh ngược (v -> u) ban đầu có khả năng thông qua = 0
        adj[v].push_back(edges.size());
        edges.push_back({u, 0, 0});
    }

    // Bước 1: Dùng BFS xây dựng đồ thị phân tầng (Level Graph)
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int id : adj[u]) {
                int v = edges[id].to;
                long long residual = edges[id].cap - edges[id].flow;
                if (residual > 0 && level[v] == -1) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[t] != -1; // Trả về true nếu vẫn còn đường đi tới t
    }

    // Bước 2: Dùng DFS đẩy luồng cản (Blocking Flow) từ tầng thấp sang tầng cao kế tiếp
    long long dfs(int u, long long pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;

        for (int& cid = ptr[u]; cid < (int)adj[u].size(); ++cid) {
            int id = adj[u][cid];
            int v = edges[id].to;
            long long residual = edges[id].cap - edges[id].flow;

            // Chỉ đi sang đỉnh ở tầng tiếp theo và còn khả năng thông qua
            if (level[u] + 1 != level[v] || residual == 0) continue;

            long long tr = dfs(v, min(pushed, residual));
            if (tr == 0) continue;

            edges[id].flow += tr;     // Tăng luồng cạnh xuôi
            edges[id ^ 1].flow -= tr; // Giảm luồng cạnh ngược (tăng khả năng thu hồi)
            return tr;
        }
        return 0;
    }

    // Hàm tính luồng cực đại
    long long max_flow() {
        long long flow = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    Dinic dinic(n,s,t);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dinic.add_edge(u,v,w);
    }
    cout<<dinic.max_flow()<<'\n';
    return 0;
}