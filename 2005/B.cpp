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
    
    cin >> n >> m >> q;
    vector<int> A(m), B(q);
    rep(i, 0, m) {
    	cin >> A[i];
    }
    sort(all(A));
    rep(i, 0, q) {
    	cin >> B[i];
    	auto it = lower_bound(all(A), B[i]);
    	if (it == A.begin()) {
    		cout << (*it - 1) << "\n";
    	} else if (it == A.end()) {
    		cout << (B[i] - *(it - 1) + n - B[i]) << "\n";
    	} else {
    		int r = *it;
    		it--;
    		int l = *it;
    		cout << (r - l) / 2 << "\n";
    	}
    }
    
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