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

// 3 1 2
// 4 2 1 3
// 5 3 1 2 4 
// 7 5 3 1 2 4 6
void run_case() {
    
    cin >> n;
    if (n & 1) {
    	vector<int> A(n);
    	rep(i, 0, n / 2 + 1) {
    		A[i] = n - 2 * i;
    	}
    	rep(i, n / 2 + 1, n) {
    		A[i] = 2 + 2 *(i - n / 2 - 1);
    	}
    	rep(i, 0, n) {
    		cout << A[i] << " \n"[i + 1 == n];
    	}
    } else {
    	cout << "-1\n";
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