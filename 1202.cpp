#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
int n, k;
ll ans;
typedef struct gem {
	int m;
	ll v;
};

typedef struct comp {
	bool operator()(gem x, gem y) {
		if (x.v != y.v) return x.v < y.v;
		return x.m < y.m;
	}
};

priority_queue <gem, vector<gem>, comp> pq;
multiset <int> ms;

int main() {
	fastio;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int m;
		ll v;
		cin >> m >> v;
		pq.push({ m,v });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		ms.insert(c);
	}

	while (!pq.empty()) {
		int m = pq.top().m;
		ll v = pq.top().v;
		multiset<int>::iterator it = ms.lower_bound(m);

		if (it == ms.end()) pq.pop();
		
		else {
			ms.erase(it);
			pq.pop();
			ans += v;
		}
	}
	cout << ans;
	return 0;
}