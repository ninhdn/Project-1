#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<char> st;
    st.reserve(s.size());
    bool ok = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) { ok = false; break; }
            char t = st.back();
            st.pop_back();
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                ok = false;
                break;
            }
        }
    }

    if (!st.empty()) ok = false;
    cout << (ok ? 1 : 0) << endl;
    return 0;
}
