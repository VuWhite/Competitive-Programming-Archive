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
using namespace std;
void run_case() {
    int n, m, q;
    cin >> n >> m >> q;
    // if (n >= m && n >= q || q >= m && m >= n) cout << abs(n - m) + abs(m - q) << '\n';
    // else if (q >= m && n >= q || m >= q && q >= n) cout << abs(n - q) + abs(m - q) << '\n';
    // else cout << abs(q - n) + abs(m - n) << '\n';
    cout << min(abs(q - n) + abs(m - n), min(abs(n - m) + abs(m - q), abs(n - q) + abs(m - q))) << '\n';
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