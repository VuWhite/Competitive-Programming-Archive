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

// https://www.luogu.com.cn/problem/P1462

const int INF = 0x3f3f3f3f;
const int N = 4e5 + 10;
int n, m, b, cnt = 1;

int head[N], nxt[N], to[N], weight[N];

void build(int n) {
    cnt = 1;
	memset(head, 0, sizeof(head));
}

void addEdge(int u, int v, int w) {
	nxt[cnt] = head[u];
	to[cnt] = v;
	weight[cnt] = w;
	head[u] = cnt++;
}

int fare[N / 10];
ll dist[N / 10];
void run_case() {
    
    cin >> n >> m >> b;
    rep(i, 0, n) {
    	cin >> fare[i + 1];
    }
    rep(i, 0, m) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	addEdge(u, v, w);
    	addEdge(v, u, w);
    }

    int l = 0, r = 1e9 + 10, ans = r;
    auto check = [&] (int x) {
    	priority_queue<pll, vector<pll>, greater<pll>> pq;
    	memset(dist, 0x3f3f3f3f, sizeof(dist));
    	auto add = [&](int a, ll b) {
    		if (dist[a] <= b || fare[a] > x) return;
    		pq.push({dist[a] = b, a});
    	};
    	add(1, 0);
    	while (!pq.empty()) {
    		int u = pq.top().second;
    		ll d = pq.top().first;
    		pq.pop();
    		if (fare[u] <= x && dist[u] >= d) {
    			for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
    				int v = to[ei], w = weight[ei];
    				add(v, d + w);
    			}
    		}
    	}
    	if (dist[n] > b) return false;
    	return true;
    };
    while (l <= r) {
    	int mid = (r - l) / 2 + l;
    	if (check(mid)) {
    		ans = mid;
    		r = mid - 1;
    	} else {
    		l = mid + 1;
    	}
    }
    cout << (ans == 1e9 + 10 ? "AFK" : to_string(ans)) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}