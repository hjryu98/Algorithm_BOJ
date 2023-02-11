#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
using namespace std;
priority_queue <int, vector<int>> mxq;
priority_queue <int, vector<int>, greater<int> > mnq;
int n;
int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		int mxsize = mxq.size();
		int mnsize = mnq.size();

		if (mxsize == 0) mxq.push(a);
		else if (mxsize == mnsize) mxq.push(a);
		else mnq.push(a);

		if (!mxq.empty() && !mnq.empty() && mxq.top() > mnq.top()) {
			int mx = mxq.top();
			int mn = mnq.top();
			mxq.pop();
			mnq.pop();
			mxq.push(mn);
			mnq.push(mx);
		}
		cout << mxq.top() << "\n";
	}

	return 0;
}