#include <iostream>
using namespace std;
int n;
int inorder[100003], postorder[100003], index[100003];

void recur(int instart, int inend, int poststart, int postend) {
	if (instart > inend || poststart > postend) return;

	int rootidx = index[postorder[postend]];
	int leftsize = rootidx - instart;
	int rightsize = inend - rootidx;

	cout << postorder[postend] << " ";

	recur(instart, rootidx - 1, poststart, poststart + leftsize - 1);
	recur(rootidx + 1, inend, poststart + leftsize, postend - 1);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		index[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++) cin >> postorder[i];

	recur(1, n, 1, n);

	return 0;
}