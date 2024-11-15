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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	int a; cin >> a;
    	if (a >= m) {
    		cnt++;
    	} else {
    		A.push_back(a);
    	}
    }
    sort(all(A));
    if (cnt >= q) {
    	cout << 0;
    } else {
    	cout << m - A[(int)(A.size()) - q + cnt];
    }
    cout << endl;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        run_case();
    }
    return 0;
}