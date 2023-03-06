#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, ans = 999999999;
int arr[55][55];
vector <pair<int, int>> sel;
vector <pair<int, int>> house;
vector <pair<int, int>> chicken;

void run() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int curx = house[i].first;
		int cury = house[i].second;

		int tmp = 999999999;
		for (int j = 0; j < sel.size(); j++) {
			int nx = sel[j].first;
			int ny = sel[j].second;
			int dist = abs(curx - nx) + abs(cury - ny);
			tmp = min(tmp, dist);
		}
		sum += tmp;
	}
	ans = min(ans, sum);
}


void recur(int cnt, int cur, int prv) {
	if (cur >= cnt) {
		run();
		return;
	}

	for (int i = prv; i < chicken.size(); i++) {
		sel.push_back({ chicken[i].first, chicken[i].second });
		recur(cnt, cur + 1, i + 1);
		sel.pop_back();
	}
}

void solve() {
	for (int i = 1; i <= m; i++) {
		recur(i, 0, 0);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) chicken.push_back({ i,j });
			else if (arr[i][j] == 1) house.push_back({ i,j });
		}
	}

	solve();

	cout << ans;

	return 0;
}