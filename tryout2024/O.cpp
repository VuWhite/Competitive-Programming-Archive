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
    bool cir[21][360] = {0}, wall[21][360] = {0}, vis[21][360] = {0};
    rep(i, 0, n) {
    	char tp;
    	cin >> tp;
    	if (tp == 'C') {
    		int r, a1, a2;
    		cin >> r >> a1 >> a2;
    		for (int j = a1; j != a2; j = (j + 1) % 360) {
    			cir[r - 1][j] = true;
    		}
    	} else {
    		int r1, r2, a;
    		cin >> r1 >> r2 >> a;
    		rep(j, r1, r2) {
    			wall[j][a] = true;
    		}
    	}
    }
    queue<pii> q;
    auto enq = [&] (int x, int y) {
    	if (!vis[x][y]) {
    		vis[x][y] = true;
	    	q.push(make_pair(x, y));
	    }
    };
    enq(0, 0);
    while (!q.empty()) {
    	auto [x, y] = q.front();
    	q.pop();
    	if (x == 20 || !wall[x][y]) {
    		enq(x, (y + 359) % 360);
    	}
    	if (x == 20 || !wall[x][(y + 1) % 360]) {
    		enq(x, (y + 1) % 360);
    	}
    	if (x > 0 && !cir[x - 1][y]) {
    		enq(x - 1, y);
    	}
    	if (x < 20 && !cir[x][y]) {
    		enq(x + 1, y);
    	}
    }
    bool fl = *max_element(vis[20], vis[20] + 360);
    cout << (fl ? "YES" : "NO") << '\n';
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