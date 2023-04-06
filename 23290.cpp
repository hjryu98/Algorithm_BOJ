#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int m, s, ans, sx, sy, val = -1, useval = -1, numval[5];
int dx[] = { 0, -1, -1, -1,0,1,1,1 }; //물고기를 위한 벡터
int dy[] = { -1, -1, 0,1,1,1,0, -1 };
int sdx[] = { -1,0,1,0 }; //상어를 위한 벡터
int sdy[] = { 0,-1,0,1 };
vector <int> v[10][10];
pair<int, int> moveset[5]; //어디좌표를 지나갈지 저장하는 배열(상어)
vector <pair<int, int>> useset;
int smell[10][10]; //2 초기, 한단계 지나고 1, 없어질 때 or 없을 때0
bool check[10][10];

bool range(int x, int y) {
	return x >= 1 && x <= 4 && y >= 1 && y <= 4;
}

void copy_magic(vector <int> copyfish[10][10]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < copyfish[i][j].size(); k++) {
				v[i][j].push_back(copyfish[i][j][k]);
			}
		}
	}
}

void dis_smell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell[i][j] > 0) smell[i][j]--;
		}
	}
}

void recur(int cnt, int x, int y, int sum) {

	if (cnt >= 3) {
		if (val < sum) {
			val = sum;
			useval = 100 * numval[0] + 10 * numval[1] + numval[2];
			useset.clear();
			for (int i = 0; i < 3; i++) {
				useset.push_back({ moveset[i].first, moveset[i].second });
			}
		}
		else if (val == sum) {
			int compval = 100 * numval[0] + 10 * numval[1] + numval[2];

			if (compval < useval) {
				useval = compval;
				useset.clear();
				for (int i = 0; i < 3; i++) {
					useset.push_back({ moveset[i].first, moveset[i].second });
				}
			}
			return;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + sdx[i];
		int ny = y + sdy[i];

		if (!range(nx, ny)) continue;

		moveset[cnt] = { nx,ny };
		numval[cnt] = i + 1;

		if (check[nx][ny]) recur(cnt + 1, nx, ny, sum);
		else if (!check[nx][ny]) {
			check[nx][ny] = true;
			recur(cnt + 1, nx, ny, sum + v[nx][ny].size());
			check[nx][ny] = false;
		}
		moveset[cnt] = { 0, 0 };
		numval[cnt] = 0;
	}
}

void sharkmove() {
	recur(0, sx, sy, 0);

	//냄새를 남겨야함 여기서 상어가 지나가면서.

	for (int i = 0; i < useset.size(); i++) {
		int x = useset[i].first;
		int y = useset[i].second;
		if (!v[x][y].empty()) {
			smell[x][y] = 3;
			v[x][y].clear();
		}
	}
	sx = useset[2].first;
	sy = useset[2].second;

	useset.clear();
	val = useval = -1;
	memset(numval, 0, sizeof(numval));
	memset(check, false, sizeof(check));
	for (int i = 0; i < 5; i++) moveset[i] = { 0,0 };
}

void copying(vector <int> tmp[10][10]) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			v[i][j].clear();

			for (int k = 0; k < tmp[i][j].size(); k++) {
				v[i][j].push_back(tmp[i][j][k]);
			}
		}
	}
}

void move() {
	vector <int> tmp[10][10]; //for copy to v
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			int size = v[i][j].size();
			int rep = 0;

			for (int k = 0; k < size; k++) {
				int dir = v[i][j][k];
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (rep == 8) {
					tmp[i][j].push_back(v[i][j][k]);
					rep = 0;
					continue;
				}

				if (!range(nx, ny) || (nx == sx && ny == sy) || smell[nx][ny] > 0) {
					v[i][j][k] = (v[i][j][k] + 7) % 8;
					k--;
					rep++;
					continue;
				}

				tmp[nx][ny].push_back(v[i][j][k]);
				rep = 0;
			}
		}
	}

	copying(tmp);
	sharkmove();
	dis_smell();
}

void solve() {
	vector <int> copyfish[10][10];

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				copyfish[i][j].push_back(v[i][j][k]);
			}
		}
	}

	move();
	copy_magic(copyfish);
}

int main() {
	fastio;
	cin >> m >> s;

	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v[x][y].push_back(d - 1); //해당 좌표에 d라는 방향을 가진 물고기가 몇개 있는가?
	}
	cin >> sx >> sy;

	while (s--) solve();

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			ans += v[i][j].size();
		}
	}
	cout << ans;

	return 0;
}