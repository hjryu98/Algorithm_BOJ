#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int n, total, arr[55];
bool flag;
bool check[55];
vector <int> dive;
vector <int> res; //답 저장
vector <int> answer;
void recur(int rem, int sum, int& target) {
	if (flag) return;

	if (sum == target) sum = 0;

	if (!rem) {
		flag = true;
		for (int i = 0; i < res.size(); i++) answer.push_back(res[i]);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		int value = arr[i];

		if (value + sum > target) continue;

		check[i] = true;
		res.push_back(value);
		recur(rem - arr[i], sum + value, target);
		check[i] = false;
		res.pop_back();
	}
}

int main() {
	fastio;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	int maxval = *max_element(arr, arr + n);

	for (int i = 1; i <= (int)sqrt(total); i++) {
		if (total % i == 0) {
			dive.push_back(i);
			dive.push_back(total / i);
		}
	}
	sort(dive.begin(), dive.end());
	sort(arr, arr + n, greater<int>());


	for (int i = 0; i < dive.size(); i++) {
		int cur = dive[i];
		if (cur < maxval) continue; // 불가능한 경우
		int tmp = total;

		for (int j = 0; j < n; j++) {
			if (arr[j] == cur) {
				check[j] = true;
				answer.push_back(cur);
				tmp -= cur;
			}
		}

		for (int j = 0; j < n; j++) {
			if (check[j]) continue;
			for (int k = 0; k < n; k++) {
				if (check[k]) continue;

				if (j == k) continue;

				if (arr[j] + arr[k] == cur) {
					check[j] = check[k] = true;
					answer.push_back(arr[j]);
					answer.push_back(arr[k]);
					tmp -= cur;
					break;
				}
			}
		}

		recur(tmp, 0, cur);

		if (flag) {
			cout << cur << "\n";

			int summation = 0;
			// cout << answer.size() << "\n";
			for (int j = 0; j < answer.size(); j++) {
				cout << answer[j] << " ";
				summation += answer[j];
				if (summation == cur) {
					cout << "\n";
					summation = 0;
				}
			}
			break;
		}
		answer.clear();
		memset(check, false, sizeof(check));
	}

	return 0;
}