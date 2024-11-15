#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <functional>
#include <stack>
#include <random>
#include <ctime>
#include <iomanip>
#include <numeric>

#define all(arr) arr.begin(), arr.end()
#define ll long long
#define MS(arr, val) memset(arr, val, sizeof(arr))
#define vi vector<int>
#define pb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lll __int128
#define ull unsigned long long
#define Kases int T; rd(T); rep(kase, 1, T)
#define rep(i, a, b) for(int i = (a), __ ## i = (b); i < __ ## i; ++i)
#define per(i, b, a) for(int i = (b), __ ## i = (a); i >= __ ## i; --i)
using namespace std;

const int INF = 0x3f3f3f3f;
ll n, m, k;
const int C = 5931642;
vector<long long> primes;
void build() {
    vector<bool> is_prime(C, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= C; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= C; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

map<long long, int> trial_division4(long long n, vector<ll> &fnum) {
    map<long long, int> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization[d]++;
            if (factorization[d] == 1)
                fnum.push_back(d);
            n /= d;
        }
    }
    if (n > 1) {
        factorization[n]++;
        if (factorization[n] == 1)
            fnum.push_back(n);
    }
    return factorization;
}

void run_case() {
    
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    // for (ll i = 1; i * i <= k && i <= n; i++) {
    //     if (k % i == 0) {
    //         if (k / i <= m) {
    //             cout << "SI\n";
    //             return;
    //         }
    //     }
    // }
    vector<ll> fnum;
    map<ll, int> fac = trial_division4(k, fnum);
    function<bool(ll, int)> check = [&] (ll cur, int idx) {
        if (cur <= n && k / cur <= m) {
            return true;
        }
        if (cur >= k / cur || idx >= fnum.size() || cur > n) {
            return false;
        }
        bool res = false;
        ll tmp = 1;
        for (int i = 0; i <= fac[fnum[idx]]; i++) {
            res = res || check(cur * tmp, idx + 1);
            if (res) return true;
            tmp *= fnum[idx];
            if (tmp > n) return false;
        }
        return res;
    };
    bool ans = check(1, 0);
    // for (auto [a, b]: fac) {
    //     cout << a << ' ' << b << '\n';
    // }
    cout << (ans ? "SI\n" : "NO\n");
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    build();
    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
 
    return 0;
}