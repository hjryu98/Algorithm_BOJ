#include <iostream>
#include <queue>
using namespace std;
int n;

typedef struct course {
	int s;
	int t;
};

typedef struct comp {
	bool operator()(course x, course y) {
		if (x.s != y.s) return x.s > y.s;
		return x.t > y.t;
	}
};
priority_queue <course, vector<course>, comp> pq;
priority_queue <int, vector<int>, greater<int> > tq;
int main() {
	cin >> n;
	while (n--) {
		int t, s;
		cin >> s >> t;
		pq.push({ s,t });
	}

	while (!pq.empty()) {
		int cs = pq.top().s;
		int ct = pq.top().t;
		pq.pop();

		if (tq.empty()) tq.push(ct);

		else {
			if (tq.top() <= cs) {
				tq.pop();
				tq.push(ct);
			}
			else tq.push(ct);
		}
	}
	cout << tq.size();

	return 0;
}