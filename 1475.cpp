#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[11];
string num;
int main() {
	cin >> num;
	for (int i = 0; i < num.size(); i++) arr[(int)(num[i] - '0')]++;
	arr[6] += arr[9];
	arr[6] = (int)ceil((double)arr[6] / 2);
	cout << *max_element(arr, arr + 9);

	return 0;
}