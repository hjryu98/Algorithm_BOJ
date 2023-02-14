#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
vector <pair<int, int>> v;
vector <pair<pair<int, int>, int>> arc;
int par[1005];

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);

    par[a] = b;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    for (int i = 0; i < 1005; i++) par[i] = i;

    int size = v.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int dist = (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second);
            arc.push_back({ {i, j}, dist });
        }
    }
    sort(arc.begin(), arc.end(), comp);

    for (int i = 0; i < arc.size(); i++) {
        int a = arc[i].first.first;
        int b = arc[i].first.second;
        int c = arc[i].second;

        if (find(a) != find(b)) {
            ans = max(ans, c);
            merge(a, b);
        }
    }
    cout << ans;

    return 0;
}