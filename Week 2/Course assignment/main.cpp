#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int crd[35];
int lb[15];

// Danh sách các môn giáo viên có thể dạy: can_teach[t][c] = true nếu GV t dạy được môn c
bool can_teach[15][35];

// Ma trận xung đột: conflict[c1][c2] = true nếu môn c1 và c2 bị trùng lịch
bool conflict[35][35];

// Trạng thái hiện tại trong quá trình quay lui
int current_load[15];              // Tổng tín chỉ hiện tại của mỗi GV
int course_count[15];              // Số môn hiện tại của mỗi GV
vector<int> assigned_courses[15];  // Danh sách các môn mà GV t đang nhận

int min_max_load = 1e9; // Lưu kết quả tải cực đại nhỏ nhất

// Hàm kiểm tra xem có gán được môn c cho GV t không
bool check(int c, int t) {
    // 1. GV t có dạy được môn c không?
    if (!can_teach[t][c]) return false;

    // 2. Môn c có xung đột với môn nào GV t ĐANG DẠY không?
    for (int prev_c : assigned_courses[t]) {
        if (conflict[c][prev_c]) return false;
    }

    return true;
}

// Hàm quay lui gán từng môn từ 1 đến n
void backtrack(int c) {
    // Đã phân công xong tất cả n môn
    if (c > n) {
        // Kiểm tra xem tất cả GV đã đạt chỉ tiêu tối thiểu (LB) chưa
        for (int t = 1; t <= m; ++t) {
            if (course_count[t] < lb[t]) return;
        }

        // Tính tải lớn nhất trong các GV
        int current_max = 0;
        for (int t = 1; t <= m; ++t) {
            current_max = max(current_max, current_load[t]);
        }

        // Cập nhật kết quả tốt nhất
        min_max_load = min(min_max_load, current_max);
        return;
    }

    // Thử gán môn c cho từng giáo viên t từ 1 đến m
    for (int t = 1; t <= m; ++t) {
        if (check(c, t)) {
            // Nhánh cận đơn giản: nếu thêm môn c mà tải của GV t đã >= kết quả tốt nhất hiện có
            // thì không cần xét tiếp nhánh này nữa
            if (current_load[t] + crd[c] >= min_max_load) continue;

            // 1. Gán môn c cho GV t
            current_load[t] += crd[c];
            course_count[t]++;
            assigned_courses[t].push_back(c);

            // 2. Đi tiếp sang môn c + 1
            backtrack(c + 1);

            // 3. Hoàn tác (Backtrack)
            current_load[t] -= crd[c];
            course_count[t]--;
            assigned_courses[t].pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> m >> n)) return 0;

    // Đọc danh sách môn mỗi GV có thể dạy
    for (int t = 1; t <= m; ++t) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;
            can_teach[t][c] = true;
        }
    }

    // Đọc tín chỉ từng môn
    for (int i = 1; i <= n; ++i) {
        cin >> crd[i];
    }

    // Đọc số môn tối thiểu (LB) của từng GV
    for (int t = 1; t <= m; ++t) {
        cin >> lb[t];
    }

    // Đọc các cặp môn xung đột
    int k_conflict;
    cin >> k_conflict;
    for (int i = 0; i < k_conflict; ++i) {
        int u, v;
        cin >> u >> v;
        conflict[u][v] = conflict[v][u] = true;
    }

    // Bắt đầu quay lui từ môn 1
    backtrack(1);

    // In kết quả
    if (min_max_load >= 1e9) {
        cout << -1 << "\n";
    } else {
        cout << min_max_load << "\n";
    }

    return 0;
}