#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Hàm kiểm tra tính hợp lệ về mặt cú pháp của biểu thức
bool isValid(const string &s) 
{
    if (s.empty()) return false;
    
    // Ký tự đầu tiên và cuối cùng bắt buộc phải là chữ số
    if (!isdigit(s.front()) || !isdigit(s.back())) return false;

    for (int i = 0; i < (int)s.length(); i++) 
    {
        // Chỉ cho phép chữ số, dấu '+' hoặc dấu '*'
        if (!isdigit(s[i]) && s[i] != '+' && s[i] != '*') 
        {
            return false;
        }

        // Không được có hai toán tử đứng cạnh nhau
        if ((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*')) 
        {
            return false;
        }
    }
    return true;
}

// Hàm tính giá trị biểu thức modulo 10^9 + 7
long long evaluate(const string &s) 
{
    long long total_sum = 0;    // Tổng các cụm phép nhân (các số hạng phân tách bởi dấu +)
    long long current_term = 0; // Giá trị tích hiện tại
    
    int i = 0;
    int n = s.length();

    // Đọc số đầu tiên
    while (i < n && isdigit(s[i])) 
    {
        current_term = (current_term * 10 + (s[i] - '0')) % MOD;
        i++;
    }

    // Duyệt qua các toán tử và toán hạng tiếp theo
    while (i < n) 
    {
        char op = s[i];
        i++; // Bỏ qua dấu toán tử

        long long next_num = 0;
        while (i < n && isdigit(s[i])) 
        {
            next_num = (next_num * 10 + (s[i] - '0')) % MOD;
            i++;
        }

        if (op == '*') 
        {
            // Gặp '*' thì nhân dồn vào số hạng hiện tại
            current_term = (current_term * next_num) % MOD;
        } 
        else if (op == '+') 
        {
            // Gặp '+' thì chốt số hạng hiện tại cộng vào tổng, và khởi tạo số hạng mới
            total_sum = (total_sum + current_term) % MOD;
            current_term = next_num;
        }
    }

    // Cộng số hạng cuối cùng vào tổng
    total_sum = (total_sum + current_term) % MOD;
    return total_sum;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    if (!getline(cin, s)) return 0;

    // Loại bỏ ký tự xuống dòng thừa nếu chạy trên môi trường Windows (\r)
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) 
    {
        s.pop_back();
    }

    if (!isValid(s)) 
    {
        cout << "NOT_CORRECT\n";
    } 
    else 
    {
        cout << evaluate(s) << '\n';
    }

    return 0;
}