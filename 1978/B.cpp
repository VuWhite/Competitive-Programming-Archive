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
template<typename T> inline void rd(T &x){
    x = 0; bool is = 0; char ch = getchar();
    while(!isdigit(ch)) is |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    is && (x = -x);
}
void run_case() {
	// an + (b + 1 - a)k - (k^2 + k) / 2 == -1/2 k^2 + (b + 1/2 - a)k + an
	// a(n - k) + (b + 1)k - (1 + 2 + ... + k) = an - ak + bk + k - (k + 1)k/2 = -0.5k^2 + (b - a + 1/2)k + an
    ll n, a, b;
    rd(n);
    rd(a);
    rd(b);
    if (a >= b) {
    	printf("%lld\n", a * n);
    } else {
    	long double k = min(b - a + 0.5, n * 1.0);
    	//ll ans = max(a * n + (b + 1 - a) * k - (k * k + k) / 2, a * n + (b + 1 - a) * k - (k * k + k) / 2);
    	ll ans = a * n + (b + 1 - a) * k - (k * k + k) / 2;
    	// if (k < n) k++;
    	// ans = max(ans, a * n + (b + 1 - a) * k - (k * k + k) / 2);
    	printf("%lld\n", ans);
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    rd(t);
    while (t--) {
        run_case();
    }
 
    return 0;
}