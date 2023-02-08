#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
vector <int> res;
queue <int> q;
int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) q.push(i);

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		cnt++;
		q.pop();
		
		if (cnt != k) q.push(cur);
		else {
			cnt = 0;
			res.push_back(cur);
		}
	}
	cout << "<";
	for (int i = 0; i < res.size() - 1; i++) cout << res[i] << ", ";
	cout << res[res.size() - 1] << ">";
	return 0;
}