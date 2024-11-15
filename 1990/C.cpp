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
    cin >> n;
    vector<int> A(n);
    ll sum = 0;
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
    	int a; cin >> a;
    	sum += a;
    	if (mp[a]) mx = max(a, mx);
    	A[i] = mx;
    	mp[a]++;
    }
    map<int, int> mp2;
    for (int i = 0; i < n; i++) {
        mp2[-A[i]]++;
        cout << A[i] << " \n"[i + 1 == n];
    }
    ll lst = 0;
    for (auto [a, b]: mp2) {
        int num = -a;
        sum += (1LL + b) * b / 2 * num;
        if (b > 1) sum += lst * num * b;
        lst += b;
    }
    
    cout << sum << '\n';
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