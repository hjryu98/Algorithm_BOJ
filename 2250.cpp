#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef struct Tree {
	int left;
	int right;
};

int n, ans, level, root;
int cnt = 1, idx = 1;
Tree arr[10005];
vector <int> col[10005];
set <int> s;

void dfs(int cur, int depth) {
	idx = max(idx, depth);

	if (arr[cur].left == -1 && arr[cur].right == -1) {
		col[depth].push_back(cnt++);
		return;
	}

	if (arr[cur].left != -1) dfs(arr[cur].left, depth + 1);
	col[depth].push_back(cnt++);
	if (arr[cur].right != -1) dfs(arr[cur].right, depth + 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].left = b;
		arr[a].right = c;

		if (b != -1) s.insert(b);
		if (c != -1) s.insert(c);
	}

	for (int i = 1; i <= n; i++) {
		if (!s.count(i)) {
			root = i;
			break;
		}
	}

	dfs(root, 1);

	for (int i = 1; i <= idx; i++) sort(col[i].begin(), col[i].end());

	for (int i = 1; i <= idx; i++) {
		int size = col[i].size();

		if (col[i][size - 1] - col[i][0] + 1 > ans) {
			level = i;
			ans = col[i][size - 1] - col[i][0] + 1;
		}
	}
	cout << level << " " << ans;

	return 0;
}