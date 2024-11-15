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
#define ll int64_t
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

ll A[200005];
int idx[200005];

void run_case() {
    
    cin >> n;
    int cnt = 0, l = 0;
    for (int i = 0; i < n; i++) {
    	int t, c;
    	cin >> t;
    	if (t == 1) {
    		A[i + 1] = A[i];
    		idx[cnt++] = i;	
    	} else {
    		cin >> c;
    		if (t == 2) {
    			A[i + 1] = A[i] + c;
    		} else {
    			A[i + 1] = A[i];
    			int ans = 0;
    			while (l < cnt && A[i + 1] - A[idx[l]] >= c) {
    				ans++;
    				l++;
    			}
    			cout << ans << '\n';
    		}
    	}
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}