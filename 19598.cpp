#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
using namespace std;
int n;
typedef struct sem {
	int s;
	int e;
};

typedef struct comp {
	bool operator()(sem x, sem y) {
		if (x.s != y.s) return x.s > y.s;
		return x.e > y.e;
	}
};
priority_queue <sem, vector<sem>, comp> pq;
priority_queue <int, vector<int>, greater<int> > tq;
int main() {
	fastio;
	cin >> n;
	while (n--) {
		int s, e;
		cin >> s >> e;
		pq.push({ s,e });
	}

	while (!pq.empty()) {
		int cs = pq.top().s;
		int ce = pq.top().e;

		pq.pop();

		if (tq.empty()) tq.push(ce);
		else {
			if (cs >= tq.top()) {
				tq.pop();
				tq.push(ce);
			}
			else {
				tq.push(ce);
			}
		}
	}
	cout << tq.size();

	return 0;
}