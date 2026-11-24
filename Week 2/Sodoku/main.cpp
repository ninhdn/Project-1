#include <bits/stdc++.h>
using namespace std;

int grid[9][9];
bool row_used[9][10];
bool col_used[9][10];
bool box_used[9][10];

struct Cell {
    int r, c;
};
vector<Cell> empty_cells;
int solution_count = 0;

int get_box_index(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void solve(int idx) {
    if (idx == empty_cells.size()) {
        solution_count++;
        return;
    }

    int r = empty_cells[idx].r;
    int c = empty_cells[idx].c;
    int b = get_box_index(r, c);

    for (int num = 1; num <= 9; ++num) {
        if (!row_used[r][num] && !col_used[c][num] && !box_used[b][num]) {
            row_used[r][num] = col_used[c][num] = box_used[b][num] = true;
            solve(idx + 1);
            row_used[r][num] = col_used[c][num] = box_used[b][num] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
            int val = grid[i][j];
            if (val == 0) {
                empty_cells.push_back({i, j});
            } else {
                row_used[i][val] = true;
                col_used[j][val] = true;
                box_used[get_box_index(i, j)][val] = true;
            }
        }
    }

    solve(0);

    cout << solution_count << "\n";
    return 0;
}