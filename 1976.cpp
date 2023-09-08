#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool check[205];
int par[205];
int arr[1005];

void init() {
	for (int i = 0; i < 205; i++) par[i] = i;
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) par[a] = b;
	else par[b] = a;
}

int main() {
	init();

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) { 
			int a;
			cin >> a;
			if (a) {
				if (find(i) != find(j)) merge(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) cin >> arr[i];

	int comp = find(arr[0]);
	bool flag = true;
	for (int i = 1; i < m; i++) {
		if (comp != find(arr[i])) {
			flag = false;
			break;
		}
	}
	cout << ((flag) ? "YES" : "NO");

	return 0;
}