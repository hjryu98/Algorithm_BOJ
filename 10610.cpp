#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char arr[100005];

bool comp(char a, char b) {
	return a > b;
}

int main() {
	cin >> arr;
	int len = strlen(arr);
	sort(arr, arr + len, comp);
	
	if (arr[len - 1] != '0') {
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += (arr[i] - '0');
	}
	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	cout << arr;

	return 0;
}