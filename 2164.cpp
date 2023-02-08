#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
int n;
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() != 1) {
		q.pop();

		int f = q.front();
		q.pop();
		q.push(f);
	}

	cout << q.front() << "\n";

	return 0;
}