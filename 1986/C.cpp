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
template<typename T> inline void rd(T &x){
    x = 0; bool is = 0; char ch = getchar();
    while(!isdigit(ch)) is |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    is && (x = -x);
}
void run_case() {
    int n, m, q;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    vector<int> ind(m); rep(i, 0, m) cin>> ind[i];
    cin >> s2;
    sort(all(s2));
    sort(all(ind));
    vector<int> tg(n, 0);
    int j = 0;
    rep(i, 0, m) {
        if (!tg[ind[i] - 1])
    	   s1[ind[i] - 1] = s2[j++], tg[ind[i] - 1] = 1;
    }
    cout << s1 << '\n';
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