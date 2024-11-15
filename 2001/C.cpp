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
int n, m, q;



void run_case() {
    
    cin >> n;
    vector<pii> res;
    set<pii> q;
    vector<int> r1(n + 1, 1);
    set<int> fi;
    rep(i, 2, n + 1) {
        cout << "? " << 1 << ' ' << i << endl;
        cin >> r1[i];
        if (r1[i] == 1) {
            res.push_back({1, i});
        } else {
            if (i < r1[i])
                q.insert({i, r1[i]});
            else
                q.insert({r1[i], i});
        }
    }
    while (!q.empty() && res.size() != n - 1) {
        auto [a, b] = *(q.begin());
        q.erase(q.begin());
        cout << "? " << a << ' ' << b << endl;
        int c;
        cin >> c;
        if (c == a) {
            res.push_back({a, b});
        } else {
            if (b < c)
                q.insert({b, c});
            else
                q.insert({c, b});
        }
    }
    cout << "! ";
    for (auto [a, b]: res) {
    	cout << a << ' ' << b << ' ';
    }
    cout << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
 
    return 0;
}