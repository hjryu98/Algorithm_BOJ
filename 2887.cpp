#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
int par[100005];
ll ans;
vector < pair < pair<ll, ll>, pair < ll, ll>>> v;
vector <pair<ll, pair<ll, ll>>> edge;

bool comp1(pair < pair<ll, ll>, pair < ll, ll>> a, pair < pair<ll, ll>, pair < ll, ll>> b) {
	return a.first.second < b.first.second;
}

bool comp2(pair < pair<ll, ll>, pair < ll, ll>> a, pair < pair<ll, ll>, pair < ll, ll>> b) {
	return a.second.first < b.second.first;
}

bool comp3(pair < pair<ll, ll>, pair < ll, ll>> a, pair < pair<ll, ll>, pair < ll, ll>> b) {
	return a.second.second < b.second.second;
}

bool comp4(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) {
	return a.first < b.first;
}

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) par[a] = b;
	else par[b] = a;
}

int main() {
	fastio;
	cin >> n;

	for (int i = 0; i < 100005; i++) par[i] = i;

	for (int i = 0; i < n; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		v.push_back({ {i,x},{y,z} });
	}

	sort(v.begin(), v.end(), comp1);
	for (int i = 0; i < n - 1; i++) {
		ll val = v[i + 1].first.second - v[i].first.second;
		edge.push_back({ val,{v[i + 1].first.first, v[i].first.first} });
	}

	sort(v.begin(), v.end(), comp2);
	for (int i = 0; i < n - 1; i++) {
		ll val = v[i + 1].second.first - v[i].second.first;
		edge.push_back({ val,{v[i + 1].first.first, v[i].first.first} });
	}

	sort(v.begin(), v.end(), comp3);
	for (int i = 0; i < n - 1; i++) {
		ll val = v[i + 1].second.second - v[i].second.second;
		edge.push_back({ val,{v[i + 1].first.first, v[i].first.first} });
	}

	sort(edge.begin(), edge.end(), comp4);

	for (int i = 0; i < edge.size(); i++) {
		if (find(edge[i].second.first) != find(edge[i].second.second)) {
			ans += edge[i].first;
			merge(edge[i].second.first, edge[i].second.second);
		}
	}
	cout << ans;

	return 0;
}