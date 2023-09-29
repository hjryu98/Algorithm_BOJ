#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> num;
bool flag;
int res[8][4];
int arr[8][4];

void recur(int cnt) {
	if (flag) return;

	if (cnt == num.size()) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				if (res[i][j] != arr[i][j]) return;
			}
		}
		flag = true;
		return;
	}

	int pro = num[cnt].first;
	int con = num[cnt].second;
	res[pro][1]++;
	res[con][3]++;
	recur(cnt + 1);
	res[pro][1]--;
	res[con][3]--;

	res[pro][3]++;
	res[con][1]++;
	recur(cnt + 1);
	res[pro][3]--;
	res[con][1]--;

	res[pro][2]++;
	res[con][2]++;
	recur(cnt + 1);
	res[pro][2]--;
	res[con][2]--;
}

int main() {
	for (int i = 1; i <= 6; i++) {
		for (int j = i + 1; j <= 6; j++) num.push_back({ i,j });
	}

	for (int i = 1; i <= 4; i++) {
		flag = false;
		for (int j = 1; j <= 6; j++) {
			cin >> arr[j][1] >> arr[j][2] >> arr[j][3];
		}

		recur(0);
		cout << ((flag) ? 1 : 0) << " ";
	}

	return 0;
}