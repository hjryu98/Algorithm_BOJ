#include <iostream>
#include <queue>
using namespace std;
int f, s, g, u, d, ans;
bool check[1000002];
queue <int> q;
bool range(int x) {
	return x >= 1 && x <= f;
}
int main() {
	cin >> f >> s >> g >> u >> d;
	q.push(s);

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int cur = q.front();
			q.pop();
			if (cur == g) {
				cout << ans;
				return 0;
			}

			if (range(cur + u) && !check[cur + u]) {
				q.push(cur + u);
				check[cur + u] = true;
			}
			if (range(cur - d) && !check[cur - d]) {
				q.push(cur - d);
				check[cur - d] = true;
			}
		}
		ans++;
	}
	cout << "use the stairs";

	return 0;
}