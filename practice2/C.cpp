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
const double eps = 1e-9;
int n, m, q;



void run_case() {
    
    cin >> n;
    long double l = 1, r = 500000;
    auto f = [&] (long double x) {
    	long double res = 0;
    	rep(i, 1, x + 1) {
    		res += (int) sqrt(x * x - i * i);
    	}
    	return res * 4;
    };
    while (r - l >= eps) {
    	long double mid = l + (r - l) / 2;
    	if (f(mid) > n) {
    		r = mid;
    	} else {
    		l = mid;
    	}
    }
    cout << setprecision(15) << l << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}