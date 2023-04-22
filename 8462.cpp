#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

ll arr[100002], res[100002];
ll cnt[1000002], n, t, cur;
struct query {
	int s, e, num;
};

bool comp(query a, query b) {
	int val = sqrt(n);

	if (a.s / val != b.s / val) return a.s / val < b.s / val;
	return a.e < b.e;
}

vector <query> q;
int main() {
	fastio;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back({ a,b,i });
	}
	sort(q.begin(), q.end(), comp); //query sorting
	int s = q[0].s;
	int e = q[0].e;
	int num = q[0].num;
	
	for (int i = s; i <= e; i++) {
		cur -= (cnt[arr[i]] * cnt[arr[i]]++ * arr[i]);
		cur += (cnt[arr[i]] * cnt[arr[i]] * arr[i]);
	}
	res[num] = cur;
	for (int i = 1; i < t; i++) {
		int cs = q[i].s;
		int ce = q[i].e;
		int cnum = q[i].num;

		while (s < cs) {
			cur -= (cnt[arr[s]] * cnt[arr[s]]-- * arr[s]);
			cur += (cnt[arr[s]] * cnt[arr[s]] * arr[s++]);
		}
		while (s > cs) {
			cur -= (cnt[arr[--s]] * cnt[arr[s]]++ * arr[s]);
			cur += (cnt[arr[s]] * cnt[arr[s]] * arr[s]);
		}
		while (e < ce) {
			cur -= (cnt[arr[++e]] * cnt[arr[e]]++ * arr[e]);
			cur += (cnt[arr[e]] * cnt[arr[e]] * arr[e]);
		}
		while (e > ce) {
			cur -= (cnt[arr[e]] * cnt[arr[e]]-- * arr[e]);
			cur += (cnt[arr[e]] * cnt[arr[e]] * arr[e--]);
		}
		res[cnum] = cur;
	}

	for (int i = 0; i < t; i++) cout << res[i] << "\n";


	return 0;
}