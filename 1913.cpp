#include <iostream>
using namespace std;
int arr[1100][1100];
int n, cur, idx = 1, dir = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ax, ay;
int main() {
	cin >> n >> cur;
	int x = n / 2 + 1, y = n / 2 + 1;
	int sum = 0;
	int idxsum = 0;

	for (int i = 1; i <= n * n; i++) {
		arr[x][y] = i;
		if (i != 1) {
			sum++;
		}

		if (sum == idx) {
			idxsum++;
			sum = 0;
			dir = (1 + dir) % 4;
		}

		if (idxsum == 3) break;

		if (idxsum == 2) {
			idxsum = 0;
			idx++;
		}
		
		x += dx[dir];
		y += dy[dir];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == cur) {
				ax = i;
				ay = j;
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << ax << " " << ay;


	return 0;
}