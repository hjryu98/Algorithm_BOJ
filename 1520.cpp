#include <iostream>
using namespace std;
/*
항상 내리막길로만 이동하는 경로의 개수?
일일히 모든 경우의 수를 탐색하면 너무 오래걸림 
-> dp를 써서 지금까지 온 좌표까지 가는 경우의 수를 더해서 탑다운으로 진행
*/
int m, n; // 행 열
int arr[510][510];
int dp[510][510]; //10억 이하임이 보장
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < 510; i++) {
		for (int j = 0; j < 510; j++) dp[i][j] = -1;
	}
}

bool range(int x, int y) {
	return x >= 1 && x <= m && y >= 1 && y <= n;
}

int recur(int x, int y) {
	if (x == m && y == n) return 1;

	if (dp[x][y] != -1) return dp[x][y];

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!range(nx, ny)) continue;

		if (arr[x][y] <= arr[nx][ny]) continue;

		ret += recur(nx, ny);
	}
	return dp[x][y] = ret;
}

int main() {
	init();
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	cout << recur(1, 1);

	return 0;
}