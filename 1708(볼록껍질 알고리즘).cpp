#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
typedef struct Point {
	ll x;
	ll y;
	bool operator < (const Point& a) {
		return y == a.y ? x < a.x : y < a.y;
	}
};
int n;
Point arr[100002];
int st[100002];
int top = 0;
void push(int a) {
	st[top++] = a;
}

ll distance(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int ccw(Point p1, Point p2, Point p3) {
	ll cp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);

	if (cp > 0) return 1;
	else if (cp < 0) return -1;
	else return 0;
}

bool comp(Point p1, Point p2) {
	int val = ccw(arr[0], p1, p2);
	if (val == 0) return distance(arr[0], p1) < distance(arr[0], p2);
	else return val > 0;

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		arr[i].x = x;
		arr[i].y = y;
	}
	sort(arr, arr + n);
	sort(arr + 1, arr + n, comp);

	push(0);
	push(1);

	for (int i = 2; i < n; i++) {
		while (top >= 2 && ccw(arr[i], arr[st[top - 2]], arr[st[top - 1]]) <= 0) top--;
		push(i);
	}
	cout << top;

	return 0;
}