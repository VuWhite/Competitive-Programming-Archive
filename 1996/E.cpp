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
const int MOD = 1e9 + 7;
void run_case() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pre(n + 1, 0);
    rep(i, 0, n) pre[i + 1] = pre[i] - (s[i] == '0') + (s[i] - '0');
    long long ans = 0;
    map<int, long long> cnt;
    rep(i, 0, n + 1) {
        ans = (ans + cnt[pre[i]] * (n - i + 1)) % MOD;
        cnt[pre[i]] += i + 1;
    }
    cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
 
    return 0;
}