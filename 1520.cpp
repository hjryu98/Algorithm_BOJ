#include <iostream>
using namespace std;
/*
�׻� ��������θ� �̵��ϴ� ����� ����?
������ ��� ����� ���� Ž���ϸ� �ʹ� �����ɸ� 
-> dp�� �Ἥ ���ݱ��� �� ��ǥ���� ���� ����� ���� ���ؼ� ž�ٿ����� ����
*/
int m, n; // �� ��
int arr[510][510];
int dp[510][510]; //10�� �������� ����
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