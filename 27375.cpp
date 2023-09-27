#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<pair<int, int>, int>> classes;
int n, k;
int ans;
bool check[7][12];

void recur(int cur, int grade) {
	if (grade == k) {
		ans++;
		return;
	}

	for (int i = cur + 1; i < classes.size(); i++) {
		int weekday = classes[i].second;
		int start = classes[i].first.first;
		int end = classes[i].first.second;
		bool flag = true;

		if (end - start + 1 + grade > k) continue;

		for (int j = start; j <= end; j++) {
			if (check[weekday][j]) {
				flag = false;
				break;
			}
		}


		if (flag) {
			for (int j = start; j <= end; j++) check[weekday][j] = true;
			recur(i, grade + end - start + 1);
			for (int j = start; j <= end; j++) check[weekday][j] = false;
		}

	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int w, s, e;
		cin >> w >> s >> e;
		if (w == 5) continue;
		classes.push_back({ {s,e}, w });
	}

	recur(-1, 0);

	cout << ans;

	return 0;
}