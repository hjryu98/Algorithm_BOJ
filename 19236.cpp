#include <iostream>
#include <algorithm>
using namespace std;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ans;
int sx, sy;
int arr[10][10];
struct Fish {
	int x;
	int y;
	int d;
	bool live;
};

Fish farr[20];
bool range(int x, int y) {
	return x >= 1 && x <= 4 && y >= 1 && y <= 4;
}

void swapping(int idx, int iidx) {
	Fish tmp = farr[idx];
	farr[idx].x = farr[iidx].x;
	farr[idx].y = farr[iidx].y;
	farr[iidx].x = tmp.x;
	farr[iidx].y = tmp.y;
}

void moving() {
	for (int i = 1; i <= 16; i++) {
		if (!farr[i].live) continue;

		bool go = true;
		int x = farr[i].x;
		int y = farr[i].y;
		int d = farr[i].d;
		int nx, ny;
		while (1) {
			nx = x + dx[d];
			ny = y + dy[d];

			if (!range(nx, ny) || arr[nx][ny] == -1) {
				d = (d + 1) % 8;

				if (d == farr[i].d) {
					go = false;
					break;
				}
				continue;
			}
			break;
		}

		if (go) {
			if (arr[nx][ny] == 0) {
				arr[x][y] = 0;
				farr[i].d = d;
				farr[i].x = nx;
				farr[i].y = ny;
				arr[nx][ny] = i;
			}
			else{
				int tmp = arr[nx][ny];
				farr[i].d = d;
				swapping(i, tmp);
				swap(arr[x][y], arr[nx][ny]);
			}
		}

	}
}

void copying(int arr[10][10], int carr[10][10], Fish farr[20], Fish cfarr[20]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) carr[i][j] = arr[i][j];
	}
	for (int i = 1; i <= 16; i++) cfarr[i] = farr[i];
}

void recur(int x, int y, int d, int sum) {
	ans = max(ans, sum);
	int carr[10][10];
	Fish cfarr[20];

	copying(arr, carr, farr, cfarr);
	
	moving();

	for (int i = 1; i <= 3; i++) {
		int nx = x + i * dx[d];
		int ny = y + i * dy[d];

		if (!range(nx, ny)) break;

		if (arr[nx][ny] > 0) {
			int num = arr[nx][ny];
			farr[num].live = false;
			arr[nx][ny] = -1;
			arr[x][y] = 0;
			recur(nx, ny, farr[num].d, sum + num);
			arr[nx][ny] = num;
			arr[x][y] = -1;
			farr[num].live = true;
		}

	}

	copying(carr, arr, cfarr, farr);
}

int main() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int a, b;
			cin >> a >> b;

			arr[i][j] = a;
			farr[a] = { i,j,b - 1,true };
		}
	}
	
	int num = arr[1][1];
	farr[arr[1][1]].live = false;
	int dir = farr[arr[1][1]].d;
	arr[1][1] = -1;
	recur(1, 1, dir, num);
	cout << ans;

	return 0;
}