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

const int N = 3e5 + 5, P = 998244353;

struct ST {
    vector<array<int, 20>> st;
    explicit ST(vector<int> a): st(a.size()) {
        for (int i = 0; i < a.size(); i++) {
            st[i][0] = a[i];
            for (int j = 1; (1 << j) <= i + 1; j++) {
                st[i][j] = max(st[i][j - 1], st[i - (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int k = __lg(r - l + 1);
        return max(st[r][k], st[l + (1 << k) - 1][k]);
    }
};

int run_case() {
    int n;
    cin >> n;
    vector<vector<int>> nxt(n);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        nxt[u].push_back(v);
        nxt[v].push_back(u);
    }
    int s;
    cin >> s >> s; s--;
    vector<int> path;
    vector<bool> in_path(n, 0);
    function<bool(int, int)> find_path = [&](int u, int fa) {
        path.push_back(u);
        in_path[u] = true;
        if (u == s) return true;
        for (auto v : nxt[u]) {
            if (v == fa) continue;
            if (find_path(v, u)) return true;
        }
        path.pop_back();
        in_path[u] = false;
        return false;
    };
    find_path(0, 0);
    function<int(int, int)> dfs = [&](int u, int fa) {
        int res = 1;
        for (auto v : nxt[u]) {
            if (in_path[v] || v == fa) continue;
            res = max(res, dfs(v, u) + 1);
        }
        return res;
    };
    int m = path.size();
    vector<int> pv(m), sv(m);
    for (int i = 0; i < m; i++) {
        int &p = pv[i], &s = sv[i];
        for (auto v : nxt[path[i]]) {
            if (in_path[v]) continue;
            s = p = max(p, dfs(v, path[i]));
        }
        p += i; s += m - i - 1;
    }
    ST stp(pv), sts(sv);
    int l = 0, r = m - 1;
    while (l < r - 1) {
        if (pv[l] > sts.query(l + 1, r)) return true;
        else l++;
        if (l + 1 == r) {
            if (pv[l] > sv[r]) return true;
            else return false;
        }
        if (sv[r] >= stp.query(l, r - 1)) return false;
        else r--;
        if (l + 1 == r) {
            if (pv[l] > sv[r]) return true;
            else return false;
        }
    }
    if (pv[l] > sv[r]) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << (run_case() ? "Alice" : "Bob") << '\n';
    }
    return 0;
}
