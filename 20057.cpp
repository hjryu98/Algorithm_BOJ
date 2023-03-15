#include <iostream>
using namespace std;
int arr[550][550]; //���ڿ� �����ִ� ���� ���� ����
int n, ans, dir = 0; //n, ��, ���� �����ϴ� ����
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int cx, cy;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void spread(int dir, int per1, int per2, int per5, int per7, int per10, int alpha) {
	if (dir == 0) {
		if (range(cx - 1, cy + 1)) arr[cx - 1][cy + 1] += per1;
		else ans += per1;
		if (range(cx + 1, cy + 1)) arr[cx + 1][cy + 1] += per1;
		else ans += per1;

		if (range(cx - 2, cy)) arr[cx - 2][cy] += per2;
		else ans += per2;
		if (range(cx + 2, cy)) arr[cx + 2][cy] += per2;
		else ans += per2;

		if (range(cx, cy - 2)) arr[cx][cy - 2] += per5;
		else ans += per5;

		if (range(cx - 1, cy)) arr[cx - 1][cy] += per7;
		else ans += per7;
		if (range(cx + 1, cy)) arr[cx + 1][cy] += per7;
		else ans += per7;

		if (range(cx - 1, cy - 1)) arr[cx - 1][cy - 1] += per10;
		else ans += per10;
		if (range(cx + 1, cy - 1)) arr[cx + 1][cy - 1] += per10;
		else ans += per10;

		if (range(cx, cy - 1)) arr[cx][cy - 1] += alpha;
		else ans += alpha;
	}

	else if (dir == 1) {
		if (range(cx - 1, cy - 1)) arr[cx - 1][cy - 1] += per1;
		else ans += per1;
		if (range(cx - 1, cy + 1)) arr[cx - 1][cy + 1] += per1;
		else ans += per1;

		if (range(cx, cy - 2)) arr[cx][cy - 2] += per2;
		else ans += per2;
		if (range(cx, cy + 2)) arr[cx][cy + 2] += per2;
		else ans += per2;

		if (range(cx + 2, cy)) arr[cx + 2][cy] += per5;
		else ans += per5;

		if (range(cx, cy + 1)) arr[cx][cy + 1] += per7;
		else ans += per7;
		if (range(cx, cy - 1)) arr[cx][cy - 1] += per7;
		else ans += per7;

		if (range(cx + 1, cy - 1)) arr[cx + 1][cy - 1] += per10;
		else ans += per10;
		if (range(cx + 1, cy + 1)) arr[cx + 1][cy + 1] += per10;
		else ans += per10;

		if (range(cx + 1, cy)) arr[cx + 1][cy] += alpha;
		else ans += alpha;
	}

	else if (dir == 2) {
		if (range(cx - 1, cy - 1)) arr[cx - 1][cy - 1] += per1;
		else ans += per1;
		if (range(cx + 1, cy - 1)) arr[cx + 1][cy - 1] += per1;
		else ans += per1;

		if (range(cx - 2, cy)) arr[cx - 2][cy] += per2;
		else ans += per2;
		if (range(cx + 2, cy)) arr[cx + 2][cy] += per2;
		else ans += per2;

		if (range(cx, cy + 2)) arr[cx][cy + 2] += per5;
		else ans += per5;

		if (range(cx - 1, cy)) arr[cx - 1][cy] += per7;
		else ans += per7;
		if (range(cx + 1, cy)) arr[cx + 1][cy] += per7;
		else ans += per7;

		if (range(cx - 1, cy + 1)) arr[cx - 1][cy + 1] += per10;
		else ans += per10;
		if (range(cx + 1, cy + 1)) arr[cx + 1][cy + 1] += per10;
		else ans += per10;

		if (range(cx, cy + 1)) arr[cx][cy + 1] += alpha;
		else ans += alpha;
	}

	else {
		if (range(cx + 1, cy - 1)) arr[cx + 1][cy - 1] += per1;
		else ans += per1;
		if (range(cx + 1, cy + 1)) arr[cx + 1][cy + 1] += per1;
		else ans += per1;

		if (range(cx, cy - 2)) arr[cx][cy - 2] += per2;
		else ans += per2;
		if (range(cx, cy + 2)) arr[cx][cy + 2] += per2;
		else ans += per2;

		if (range(cx - 2, cy)) arr[cx - 2][cy] += per5;
		else ans += per5;

		if (range(cx, cy + 1)) arr[cx][cy + 1] += per7;
		else ans += per7;
		if (range(cx, cy - 1)) arr[cx][cy - 1] += per7;
		else ans += per7;

		if (range(cx - 1, cy - 1)) arr[cx - 1][cy - 1] += per10;
		else ans += per10;
		if (range(cx - 1, cy + 1)) arr[cx - 1][cy + 1] += per10;
		else ans += per10;

		if (range(cx - 1, cy)) arr[cx - 1][cy] += alpha;
		else ans += alpha;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	cx = cy = n / 2 + 1; //���� ��ǥ(����̵� ��ǥ)
	int cur = 0; //��� ���°�
	int cnt = 0; //���� ���̷� �� Ƚ��  == 2�� �Ǹ� lvl++, cur = 0
	int lvl = 1; //���ߵǴ� Ƚ�� >> ȸ���� ���ߵǴ� Ƚ�� = cur�� �Ǹ� ����, cnt++

	while (1) {
		cur++;

		cx += dx[dir];
		cy += dy[dir];

		int per1 = arr[cx][cy] / 100;
		int per2 = arr[cx][cy] * 2 / 100;
		int per5 = arr[cx][cy] * 5 / 100;
		int per7 = arr[cx][cy] * 7 / 100;
		int per10 = arr[cx][cy] / 10;
		int alpha = arr[cx][cy] - ((per1 + per2 + per7 + per10) * 2 + per5);

		arr[cx][cy] = 0;
		//������ >> �� �� �� ��
		spread(dir, per1, per2, per5, per7, per10, alpha);

		if (cur == lvl) {
			cnt++;
			cur = 0;
			dir = (dir + 1) % 4;
		}
		if (cnt == 2 && lvl != n - 1) {
			cnt = 0;
			lvl++;
		}

		if (cx == 1 && cy == 1) break;
	}

	cout << ans;

	return 0;
}