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

int A[27] = {1, 2, 2, 4, 4, 6, 6, 8, 8, 1, 10, 10, 12, 12, 14, 14, 16 ,16, 18, 18,
20, 20, 22, 24, 24, 1, 22};

void run_case() {
    
    cin >> n;
    if (n & 1 && n >= 26) {
    	for (int i = 0; i <= 26; i ++) {
    		cout << A[i] << ' ';
    	}
        for (int i = 28; i <= n; i += 2) {
            cout << i << ' ' << i << ' ';
        } 
    } else if (n & 1) {
    	cout << "-1\n";
    } else {
    	for (int i = 1; i <= n; i += 2) {
    		cout << i << ' ' << i << ' ';
    	}
    	cout << '\n';
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