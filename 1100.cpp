#include <iostream>
using namespace std;
string arr[10];
int ans;
int main() {
	for (int i = 0; i < 8; i++) cin >> arr[i];
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j += 2) {
				if (arr[i][j] == 'F') ans++;
			}
		}
		else {
			for (int j = 1; j < 8; j += 2) {
				if (arr[i][j] == 'F') ans++;
			}
		}
	}
	cout << ans;

	return 0;
}