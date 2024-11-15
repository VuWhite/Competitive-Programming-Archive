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

template <class T> struct SegTree {
	const T ID{};
	T cmb(T a, T b) {return max(a, b);}
	int n;
	vector<T> seg;
	void init(int _n) {
		for (n = 1; n < _n;) n *= 2;
		seg.assign(2 * n, ID);
	}
	void pull(int p) {
		seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
	}
	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) {
			pull(p);
		}
	}
	T query(int l, int r) { //zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = cmb(ra, seg[l++]);
			if (r & 1) rb = cmb(seg[--r], rb);
		}
		return cmb(ra, rb);
	}
};

template <class T> struct BIT {
	int N;
	vector<T> data;
	void init(int _N) {
		N = _N;
		data.resize(N);
	}
	void add(int p, T x) {
		for (++p; p <= N; p += p & -p) {
			data[p - 1] += x;
		}
	}
	T sum(int l, int r) {
		return sum(r + 1) - sum(l);
	}
	T sum(int r) {
		T s = 0;
		for (; r; r -= r & -r) {
			s += data[r - 1];
		}
		return s;
	}
	int lower_bound(T sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			int npos = pos + pw;
			if (npos <= N && data[npos - 1] < sum) {
				pos = npos, sum -= data[pos - 1];
			}
		}
		return pos;
	}
};

void run_case() {
    
    cin >> n >> m;
    vector<int> T(n + 1), A(n + 1);
    rep(i, 1, n + 1) {
    	cin >> T[i];
    }
    rep(i, 1, n + 1) {
    	cin >> A[i];
    }
    vector<pll> F;
    rep(i, 1, n + 1) {
    	if (A[i] + 1LL * m * T[i] >= 0LL && A[i] - 1LL * m * T[i] <= 0LL) {
    		F.pb(make_pair(A[i] + 1LL * m * T[i], A[i] - 1LL * m * T[i]));
    	}
    }
    sort(all(F), [&](pll a, pll b) {
    	if (a.first != b.first) return a.first > b.first;
    	return a.second < b.second;
    });
    multiset<ll> st;
    rep(i, 0, F.size()) {
    	auto it = st.upper_bound(F[i].second);
    	if (it != st.end()) st.erase(it);
    	st.insert(F[i].second);
    }
    cout << st.size() << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}