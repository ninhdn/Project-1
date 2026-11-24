#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000000; // Giới hạn N tối đa (thường là 1e6)

long long fact[MAXN + 5];    // fact[i] = i! % MOD
long long invFact[MAXN + 5]; // invFact[i] = (i!)^(-1) % MOD

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Hàm tìm nghịch đảo modulo của a theo modulo MOD: a^(MOD - 2) % MOD
long long modInverse(long long a) {
    return power(a, MOD - 2);
}

// Tiền xử lý giai thừa và nghịch đảo giai thừa
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    // Tính nghịch đảo của MAXN! trước
    invFact[MAXN] = modInverse(fact[MAXN]);
    
    // Quy hoạch động tính ngược lại: 1/(i-1)! = 1/i! * i
    for (int i = MAXN - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

// Hàm tính C(n, k) % MOD trong O(1)
long long nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] % MOD * invFact[k] % MOD * invFact[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    int n,k; cin>>k>>n;
    cout<<nCr(n,k)<<'\n';
    return 0;
}