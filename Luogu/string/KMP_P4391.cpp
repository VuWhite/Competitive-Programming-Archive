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

//https://www.luogu.com.cn/problem/P4391

const int INF = 0x3f3f3f3f;
vector<int> nxt;
int n, m, q;
void nextArray(string &s) {
    int n = s.length();
    nxt.resize(n + 2);
    nxt[0] = -1;
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i <= n) {
        if (s[i - 1] == s[cn]) {
            nxt[i++] = ++cn;
        } else if (cn) {
            cn = nxt[cn];
        } else {
            nxt[i++] = 0;
        }
    }
}

void run_case() {
    
    string s;
    cin >> n >> s;
    nextArray(s);

    cout << n - nxt[n] << '\n';

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}