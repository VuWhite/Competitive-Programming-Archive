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

void run_case() {
    int n, k;
    cin >> n >> k;
    vector<int> A;
    map<int, int> mp;
    rep(i, 0, n) {
    	int a; cin >> a;
    	mp[a]++;
    }
    for (auto &[a, b]: mp) {
    	if (b & 1)
            A.push_back(a);
    }
    int mx = 0;
    ll tot = 0;
    int od = n & 1, idx = -1;
    map<int, vector<int>> mp2;
    rep(i, 0, A.size()) {
        int mm = A[i] % k;
        mp2[mm].push_back(A[i] / k);
    }
    for (auto &[a, b]: mp2) {
        if (b.size() & 1) {
            if (od) {
                od = 0;
                vector<ll> pre(n + 2, 0), suf(n + 2, 0);
                for (int i = 1; i < b.size(); i += 2) {
                    pre[i] = pre[max(0, i - 2)] + b[i] - b[i - 1];
                }
                for (int i = b.size() - 2; i >= 0; i -= 2) {
                    suf[i] = suf[i + 2] + b[i + 1] - b[i];
                }
                ll cur = min(pre[max(0, (int)(b.size()) - 2)], suf[1]);
                for (int i = 2; i < b.size() - 1; i += 2) {
                    cur = min(cur, pre[i - 1] + suf[i + 1] );
                }
                tot += cur;
            } else {
                cout << -1 << '\n';
                return;
            }
        } else {
            for (int i = 0; i + 1 < b.size(); i += 2) {
                tot += b[i + 1] - b[i];
            }
        }
        
    }
    cout << tot << '\n';
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