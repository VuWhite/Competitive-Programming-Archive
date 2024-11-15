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

int dist[N / 2];
void dijkstra(int st) {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	pq.push({dist[st] = 0, 1});
	while (!pq.empty()) {
		int u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if (dist[u] == d) {
			for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
				int v = to[ei], w = weight[ei];
				if (d + w < dist[v]) {
					pq.push({dist[v] = d + w, v});
				}
			}
		}
	}
}
void editDist(int u, int v, int pos) {
	if (dist[v] <= dist[u] + 1) {
		return;
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({dist[v] = dist[u] + 1, v});
	while (!pq.empty()) {
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (dist[u] == d) {
			for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
				int v = to[ei], w = weight[ei];
				if (d + w < dist[v]) {
					pq.push({dist[v] = d + w, v});
				}
			}
		}
	}
}
int gp[N];
vector<pii> edges;
void run_case() {
    
    cin >> n >> m;
  	edges.clear();
    rep(i, 0, m) {
    	int u, v, w = 1;
    	cin >> u >> v;
    	edges.push_back({u, v});
    }
    sort(all(edges));
    rep(i, 1, n) {
    	dist[i] = i - 1;
    	addEdge(i, i + 1, 1);
    }
    string res = "";
   	pii mn = {dist[n], n};
   	int j = 0;
    rep(i, 1, n) {
    	while (j < m && edges[j].first < i) {
    		auto [u, v] = edges[j];
    		j++;
    		addEdge(u, v, 1);
    	}
    }
	cout << res << '\n';
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