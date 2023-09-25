#include <iostream>
using namespace std;
int arr[605][605];
int h, w, x, y;

bool range(int cx, int cy) {
	return cx >= 1 && cx <= h && cy >= 1 && cy <= w;
}

int main() {
	cin >> h >> w >> x >> y;

	for (int i = 1; i <= h + x; i++) {
		for (int j = 1; j <= w + y; j++) cin >> arr[i][j];
	}

	for (int i = 1 + x; i <= h + x; i++) {
		for (int j = 1 + y; j <= w + y; j++) {
			if (!range(i, j)) continue;

			arr[i][j] -= arr[i - x][j - y];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}

	return 0;
}