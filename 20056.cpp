#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct fireball {
	int m; //질량
	int s; //속력
	int d; //방향
};
int N, M, K, ans;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
vector <fireball> v[55][55]; //해당 좌표에 있는 파이어볼을 저장하는 벡터
void calc() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				ans += v[i][j][k].m;
			}
		}
	}
}


bool range(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

void copying(vector <fireball> tmp[55][55]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int size = tmp[i][j].size();
			for (int k = size - 1; k >= 0; k--) {
				int m = tmp[i][j][k].m;
				int s = tmp[i][j][k].s;
				int d = tmp[i][j][k].d;
				tmp[i][j].pop_back();
				v[i][j].push_back({ m,s,d });
			}
		}
	}
}


int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		v[r][c].push_back({ m,s,d });
	}

	while (K--) {
		vector <fireball> tmp[55][55];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][j].empty()) continue;

				int size = v[i][j].size();

				for (int k = size - 1; k >= 0; k--) {
					int cx = i, cy = j;
					int m = v[i][j][k].m;
					int s = v[i][j][k].s;
					int d = v[i][j][k].d;

					v[i][j].pop_back();

					int dist = s % N;

					cx += dx[d] * dist;
					cy += dy[d] * dist;

					if (!range(cx, cy)) {
						if (cx <= 0) while (cx <= 0) cx += N;
						if (cx > N) while (cx > N) cx -= N;
						if (cy <= 0) while (cy <= 0) cy += N;
						if (cy > N) while (cy > N) cy -= N;
					}

					tmp[cx][cy].push_back({ m,s,d });
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tmp[i][j].size() <= 1) continue;

				int sum_m = 0, sum_s = 0, size = tmp[i][j].size();
				int cnt = 0; //모두 짝수라면 cnt == size
				bool flag;

				for (int k = 0; k < size; k++) if (tmp[i][j][k].d % 2 == 0) cnt++;

				if (cnt == size || cnt == 0) flag = true;
				else flag = false;

				while (!tmp[i][j].empty()) {
					sum_m += tmp[i][j].back().m;
					sum_s += tmp[i][j].back().s;
					tmp[i][j].pop_back();
				}

				sum_m /= 5;
				sum_s /= size;

				if (sum_m == 0) continue;

				if (flag) {
					tmp[i][j].push_back({ sum_m, sum_s, 0 });
					tmp[i][j].push_back({ sum_m, sum_s, 2 });
					tmp[i][j].push_back({ sum_m, sum_s, 4 });
					tmp[i][j].push_back({ sum_m, sum_s, 6 });
				}
				else {
					tmp[i][j].push_back({ sum_m, sum_s, 1 });
					tmp[i][j].push_back({ sum_m, sum_s, 3 });
					tmp[i][j].push_back({ sum_m, sum_s, 5 });
					tmp[i][j].push_back({ sum_m, sum_s, 7 });
				}
			}
		}

		copying(tmp);
	}

	calc();
	cout << ans;

	return 0;
}