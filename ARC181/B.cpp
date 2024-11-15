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

void run_case() {
    string s, x, y;
    cin >> s >> x >> y;
    int n = s.length();
    ll cnt[2][2] = {0};
    rep(i, 0, x.length()) {
        cnt[0][x[i] - '0']++;
    }
    for (char c: y) {
        cnt[1][c - '0']++;
    }
    if (cnt[0][1] == cnt[1][1]) {
        if (cnt[0][0] == cnt[1][0]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    ll lenT = n * (cnt[0][0] - cnt[1][0]) / (cnt[1][1] - cnt[0][1]);
    //cout << lenT << ' ';
    if (lenT < 0) {
        cout << "No\n";
        return;
    } else if (lenT * (cnt[1][1] - cnt[0][1]) != n * (cnt[0][0] - cnt[1][0])) {
        cout << "No\n";
        return;
    }
    if (!lenT) {
        cout << "Yes\n";
        return;
    }
    int _gcd = __gcd(lenT, 1LL * n);
    string ss = s.substr(0, _gcd);
    int lenSS = ss.length();

    for (int i = lenSS; i < n; i += lenSS) {
        if (ss != s.substr(i, lenSS)) {
           cout << "No\n";
           return;
        }
    }
    cout << "Yes\n";
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