#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

const int N = 2e6 + 20;
int A[1020][1020];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<pair<int, int>>> E(1e5 + 10);


int pa[N];
int siz[N];

void init(int v) {
	pa[v] = v;
	siz[v] = 1;
}

int f(int v) {
	return (v == pa[v]) ? v : pa[v] = f(pa[v]);
}

void u(int a, int b) {
	a = f(a);
	b = f(b);
	if (a != b) {
		if (siz[a] < siz[b]) {
			swap(a, b);
		}
		pa[b] = a;
		siz[a] += siz[b];
		siz[b] = 0;
	}
}

int getSize(int v) {
	return siz[f(v)];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> A[i][j];
			if (A[i][j] <= k)
				E[A[i][j]].emplace_back(make_pair(i, j));
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			init(i * (m + 2) + j);
			if (!i || !j || j == m + 1 || i == n + 1) {
				u(0, i * (m + 2) + j);
			}
		}
	}
	int ini = getSize(0);
	for (int i = 1; i <= k; i++) {
		for (auto [a, b]: E[i]) {
			for (int j = 0; j < 4; j++) {
				int x = a + dir[j][0], y = b + dir[j][1];
				if (A[x][y] <= i) {
					u(a * (m + 2) + b, x * (m + 2) + y);
				}
			}
		}
		cout << n * m - (getSize(0) - ini) << '\n';
	}
	return 0;
}