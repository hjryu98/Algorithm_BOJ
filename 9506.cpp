#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n;
int main() {
	while (cin >> n) {
		if (n < 0) break;
		vector <int> v;
		int sum = 1;

		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				sum += i;
				sum += n / i;
				v.push_back(i);
				v.push_back(n / i);
			}
		}
		v.push_back(1);
		if (n == sum) {
			sort(v.begin(), v.end());
			cout << n << " = ";
			for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " + ";
			cout << v[v.size() - 1] << "\n";
		}
		else cout << n << " is NOT perfect.\n";
	}

	return 0;
}