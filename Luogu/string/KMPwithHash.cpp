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
const int BASE = 499;
const int MAXN = 3e6 + 10;
unsigned long long Pow[MAXN], Hash[MAXN];
unsigned long long hashRange(int l, int r) {
    unsigned long long ans = Hash[r];
    ans -= l == 0 ? 0 : (Hash[l - 1] * Pow[r - l + 1]);
    return ans;
}
int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0' + 1;
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 11;
    } else {
        return c - 'a' + 37;
    }
}
unsigned long long hashValue(string &s) {
    if (!s.length()) return 0;
    unsigned long long res = charToInt(s[0]);
    for (int i = 1; i < s.length(); i++) {
        res = res * BASE + charToInt(s[i]);
    }
    return res;
}
void build(string &s) {
    int n = s.length();
    Pow[0] = 1;
    for (int i = 1; i < n; i++) {
        Pow[i] = Pow[i - 1] * BASE;
    }  
    Hash[0] = charToInt(s[0]);
    for (int i = 1; i < n; i++) {
        Hash[i] = Hash[i - 1] * BASE + charToInt(s[i]);
    }
}
vector<int> nxt;
int n, m, q;
void nextArray(string &s) {
    int n = s.length();
    nxt.resize(n + 2);
    nxt[0] = -1;
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i <= n) {
        if (s[i - 1] == s[cn]) {
            nxt[i++] = ++cn;
        } else if (cn) {
            cn = nxt[cn];
        } else {
            nxt[i++] = 0;
        }
    }
}
void run_case() {
    string s1, s2;
    cin >> s1 >> s2;

    n = s1.length(), m = s2.length();
    ull valueS2 = hashValue(s2);
    build(s1);
    for (int l = 0, r = m - 1; r < n; l++, r++) {
    	if (hashRange(l, r) == valueS2) {
    		cout << l + 1 << '\n';
    	}
    }
    nextArray(s2);
    rep(i, 1, m + 1) {
        cout << nxt[i] << " \n"[i == m];
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t = 1;
    while (t--) {
        run_case();
    }
 
    return 0;
}