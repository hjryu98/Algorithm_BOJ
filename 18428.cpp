#include <iostream>
#include <vector>
using namespace std;
int n;
char arr[10][10];
bool ended;
vector <pair<int, int>> teacher;

bool check() {
	for (int j = 0; j < teacher.size(); j++) {
		int cx = teacher[j].first;
		int cy = teacher[j].second;

		for (int i = cx + 1; i <= n; i++) {
			if (arr[i][cy] == 'O') break;

			if (arr[i][cy] == 'S') return false;
		}

		for (int i = cx - 1; i >= 1; i--) {
			if (arr[i][cy] == 'O') break;

			if (arr[i][cy] == 'S') return false;
		}

		for (int i = cy + 1; i <= n; i++) {
			if (arr[cx][i] == 'O') break;

			if (arr[cx][i] == 'S') return false;
		}

		for (int i = cy - 1; i >= 1; i--) {
			if (arr[cx][i] == 'O') break;

			if (arr[cx][i] == 'S') return false;
		}
	}
	return true;
}


void recur(int x, int y, int cnt) {
	if (ended) return;

	if (cnt >= 3) {
		if (check()) ended = true;
		return;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= x && j <= y) continue;

			if (arr[i][j] == 'X') {
				arr[i][j] = 'O';
				recur(i, j, cnt + 1);
				arr[i][j] = 'X';
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'T') teacher.push_back({ i,j });
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 'X') {
				arr[i][j] = 'O';
				recur(i, j, 1);
				if (ended) break;
				arr[i][j] = 'X';
			}
		}
		if (ended) break;
	}
	if (ended) cout << "YES";
	else cout << "NO";


	return 0;
}