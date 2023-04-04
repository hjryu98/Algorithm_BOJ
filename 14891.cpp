#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string arr[10];
int k;

void rotate(int n, int d) {

	string tmp = "";
	if (d == 1) {
		tmp += arr[n][7];
		for (int i = 0; i <= 6; i++) tmp += arr[n][i];
	}
	else {
		tmp += arr[n][1];
		for (int i = 2; i <= 7; i++) tmp += arr[n][i];
		tmp += arr[n][0];
	}
	arr[n] = tmp;
}

void go(int n, int d) {
	int check[10] = { 0, };

	check[n] = d;

	int cur = n;
	while (1) {
		cur--;
		if (cur <= 0) break;

		if (arr[cur][2] != arr[cur + 1][6]) check[cur] = -1 * check[cur + 1];
	}

	cur = n;
	while (1) {
		cur++;
		if (cur >= 5) break;

		if (arr[cur - 1][2] != arr[cur][6]) check[cur] = -1 * check[cur - 1];
	}

	for (int i = 1; i <= 4; i++) {
		if (check[i] == 0) continue;

		rotate(i, check[i]);
	}
}

int main() {
	for (int i = 1; i <= 4; i++) cin >> arr[i];
	cin >> k;

	while (k--) {
		int n, d; //d = 1 시계, -1 반시계
		cin >> n >> d;
		go(n, d);
	}

	int ans = 0;
	for (int i = 1; i <= 4; i++) ans += ((arr[i][0] - '0') * (int)pow(2, i - 1));

	cout << ans;

	return 0;
}