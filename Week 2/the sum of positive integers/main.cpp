#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> current;

void backtrack(int remain, int min_val) {
    if (remain == 0) {
        for (int i = 0; i < (int)current.size(); ++i) {
            cout << current[i] << (i + 1 == (int)current.size() ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int v = min_val; v <= remain; ++v) {
        current.push_back(v);
        backtrack(remain - v, v);
        current.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    backtrack(n, 1);
    return 0;
}