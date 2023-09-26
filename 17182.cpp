#define inf 999999999
#include <iostream>
#include <algorithm>
using namespace std;
/*
floyd-warshall로 거리 구하고 brute force
*/
int dist[12][12];
int arr[12][12];
int n, cur, ans = inf;
bool check[12]; /// bit

void recur(int now, int value, int cnt) {
	if (cnt >= n) {
		ans = min(ans, value);
		return;
	}


	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			recur(i, value + dist[now][i], cnt + 1);
			check[i] = false;
		}
	}
}



int main() {
	cin >> n >> cur;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (arr[i][j] >= 0) dist[i][j] = arr[i][j];
		}
	}

	//n^3 -> 1000
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	check[cur] = true;
	recur(cur, 0, 1);

	cout << ans;

	return 0;
}