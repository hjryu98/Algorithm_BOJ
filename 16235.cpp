#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[15][15];
vector <int> dead[15][15];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int arr[15][15];
int cur[15][15];
int n, m, k, ans;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void copying(vector <int> tmp[15][15]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = tmp[i][j].size();

			for (int k = size - 1; k >= 0; k--) {
				int val = tmp[i][j][k];
				tmp[i][j].pop_back();
				v[i][j].push_back(val);
			}
		}
	}
}

void spring() {
	vector <int> tmp[15][15];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = v[i][j].size();

			for (int k = size - 1; k >= 0; k--) {
				int age = v[i][j][k];
				if (age > cur[i][j]) break;

				v[i][j].pop_back();

				cur[i][j] -= age;
				age++;

				tmp[i][j].push_back(age);
			}

			if (!v[i][j].empty()) while (!v[i][j].empty()) {
				dead[i][j].push_back(v[i][j].back());
				v[i][j].pop_back();
			}
		}
	}

	copying(tmp);
}

void summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < dead[i][j].size(); k++) {
				cur[i][j] += (dead[i][j][k] / 2);
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				if (v[i][j][k] % 5 != 0) continue;

				for (int l = 0; l < 8; l++) {
					int nx = i + dx[l];
					int ny = j + dy[l];

					if (!range(nx, ny)) continue;

					v[nx][ny].push_back(1);
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cur[i][j] += arr[i][j];
	}
}

void check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) ans += v[i][j].size();
	}
}


int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			cur[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x][y].push_back(z);
	}

	while (k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sort(v[i][j].begin(), v[i][j].end(), greater<int>());
				dead[i][j].clear();
			}
		}

		spring();
		summer();
		fall();
		winter();
	}
	check();
	cout << ans;

	return 0;
}