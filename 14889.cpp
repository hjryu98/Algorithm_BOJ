#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int start, link, ans = 999999999;
int arr[25][25];
bool choosed[25];
vector <int> steam;
vector <int> lteam;

void scoring() {
	for (int i = 0; i < steam.size(); i++) {
		for (int j = i + 1; j < steam.size(); j++) {
			start += (arr[steam[i]][steam[j]] + arr[steam[j]][steam[i]]);
		}
	}
	
	for (int i = 0; i < lteam.size(); i++) {
		for (int j = i + 1; j < lteam.size(); j++) {
			link += (arr[lteam[i]][lteam[j]] + arr[lteam[j]][lteam[i]]);
		}
	}
	ans = min(ans, abs(start - link));
	start = 0;
	link = 0;
}

void choosing(int cur, int cnt, int prv) {
	if (cur >= cnt) {
		for (int i = 1; i <= n; i++) {
			if (!choosed[i]) lteam.push_back(i);
		}
		scoring();
		lteam.clear();
		return;
	}

	for (int i = prv; i <= n; i++) {
		choosed[i] = true;
		steam.push_back(i);
		choosing(cur + 1, cnt, i + 1);
		steam.pop_back();
		choosed[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	choosing(0, n / 2, 1);
	cout << ans;

	return 0;
}