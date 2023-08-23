#include <iostream>
using namespace std;
char arr[6][17];
int main() {
	for (int i = 0; i < 5; i++) cin >> arr[i];
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == '\0') continue;
			cout << arr[j][i];
		}
	}

	return 0;
}