#include <iostream>
#include <queue>
using namespace std;
int n;
struct course {
	int num; int s; int e;
};

struct comp {
	bool operator()(course a, course b) {
		if (a.s != b.s) return a.s > b.s;
		return a.e > b.e;
	}
};
priority_queue <course, vector<course>, comp> pq;
priority_queue <int, vector<int>, greater<int>> tq;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, s, e;
		cin >> num >> s >> e;
		pq.push({ num, s, e });
	}
	while (!pq.empty()) {
		int s = pq.top().s;
		int e = pq.top().e;
		pq.pop();
		if (tq.empty()) {
			tq.push(e);
		}

		else {
			if (tq.top() <= s) {
				tq.pop();
				tq.push(e);
			}
			else {
				tq.push(e);
			}
		}
	}
	cout << tq.size();

	return 0;
}