#include <iostream>
#include <algorithm>
using namespace std;
int arr[11];
int res[11];
bool flag;
void recur(int x, int prv) {
	if (flag) return;

	if (x >= 7) {
		int sum = 0;
		for (int i = 0; i < 7; i++) sum += res[i];
		if (sum != 100) return;
		else {
			sort(res, res + 7);
			for (int i = 0; i < 7; i++) cout << res[i] << "\n";
			flag = true;
			return;
		}
	}
	for (int i = prv; i < 9; i++) {
		res[x] = arr[i];
		recur(x + 1, i + 1);
		res[x] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) cin >> arr[i];
	sort(arr, arr + 9);

	recur(0, 0);

	return 0;
}