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
    int n, mx = 0;
    rd(n);
    rep(i, 0, n - 1) {
    	int c;
    	rd(c);
    	mx = max(mx, c);
    }
    int tot;
    rd(tot);
    printf("%d\n", tot + mx);

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