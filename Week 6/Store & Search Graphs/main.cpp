#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

// Hàm băm 64-bit phân tán
ull mix(ull x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct Graph {
    int n, m;
    vector<vector<int>> adj;
    vector<ull> col;
    ull sig;

    bool hasEdge(int u, int v) const {
        return binary_search(adj[u].begin(), adj[u].end(), v);
    }

    void build() {
        m = 0;
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end());
            adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
            m += adj[i].size();
        }
        m /= 2;

        col.assign(n, 0);
        for (int v = 0; v < n; v++) {
            col[v] = mix(adj[v].size());
        }

        vector<ull> next_col(n);
        int rounds = min(n, 30);
        for (int r = 1; r <= rounds; r++) {
            for (int v = 0; v < n; v++) {
                ull sum_neighbors = 0;
                for (int u : adj[v]) {
                    sum_neighbors += mix(col[u]);
                }
                next_col[v] = mix(col[v] * 1000003ULL + mix(sum_neighbors) + r);
            }
            col = next_col;
        }

        vector<ull> sorted_colors = col;
        sort(sorted_colors.begin(), sorted_colors.end());

        sig = mix((ull)n * 1315423911ULL + m);
        for (ull c : sorted_colors) {
            sig = mix(sig ^ c);
        }
    }
};

const Graph *A;
const Graph *B;
vector<int> ord;
vector<int> f;
vector<bool> used;

bool isValidMatch(int x, int y) {
    if (used[y] || A->col[x] != B->col[y]) return false;

    int matched_A = 0;
    for (int z : A->adj[x]) {
        if (f[z] != -1) {
            matched_A++;
            if (!B->hasEdge(f[z], y)) return false;
        }
    }

    int matched_B = 0;
    for (int w : B->adj[y]) {
        if (used[w]) matched_B++;
    }

    return matched_A == matched_B;
}

bool dfs(int index) {
    if (index == (int)ord.size()) return true;

    int x = ord[index];
    int anchor = -1;
    for (int z : A->adj[x]) {
        if (f[z] != -1) {
            anchor = z;
            break;
        }
    }

    if (anchor != -1) {
        for (int y : B->adj[f[anchor]]) {
            if (isValidMatch(x, y)) {
                f[x] = y;
                used[y] = true;
                if (dfs(index + 1)) return true;
                f[x] = -1;
                used[y] = false;
            }
        }
    } else {
        for (int y = 0; y < B->n; y++) {
            if (isValidMatch(x, y)) {
                f[x] = y;
                used[y] = true;
                if (dfs(index + 1)) return true;
                f[x] = -1;
                used[y] = false;
            }
        }
    }
    return false;
}

bool isIsomorphic(const Graph &g1, const Graph &g2) {
    if (g1.n != g2.n || g1.m != g2.m || g1.sig != g2.sig) {
        return false;
    }

    A = &g1;
    B = &g2;
    int n = g1.n;

    ord.clear();
    vector<bool> visited(n, false);
    for (int s = 0; s < n; s++) {
        if (!visited[s]) {
            queue<int> q;
            q.push(s);
            visited[s] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                ord.push_back(u);
                for (int v : g1.adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    f.assign(n, -1);
    used.assign(n, false);
    return dfs(0);
}

void readOneGraph(Graph &g) {
    cin >> g.n >> g.m;
    g.adj.assign(g.n, vector<int>());
    for (int i = 0; i < g.m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 1-based sang 0-based
        if (u != v) {
            g.adj[u].push_back(v);
            g.adj[v].push_back(u);
        }
    }
    g.build();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Graph> database(N);
    unordered_map<ull, vector<int>> hashTable;

    // 1. Đọc N đồ thị lưu kho
    for (int i = 0; i < N; i++) {
        readOneGraph(database[i]);
        hashTable[database[i].sig].push_back(i);
    }

    // 2. Bỏ qua dấu '#' ngăn cách
    string sharp;
    cin >> sharp;

    // 3. Đọc K truy vấn (nếu có K) hoặc đọc tới hết file
    int K;
    if (cin >> K) {
        for (int q = 0; q < K; q++) {
            Graph queryGraph;
            readOneGraph(queryGraph);

            bool found = false;
            auto it = hashTable.find(queryGraph.sig);
            if (it != hashTable.end()) {
                for (int id : it->second) {
                    if (isIsomorphic(queryGraph, database[id])) {
                        found = true;
                        break;
                    }
                }
            }
            cout << (found ? 1 : 0) << "\n";
        }
    }

    return 0;
}