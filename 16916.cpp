#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <string.h>
using namespace std;
char a[1000002], b[1000002];
int main() {
	fastio;
	cin >> a >> b; 
	cout << ((strstr(a, b) != NULL) ? 1 : 0);
	return 0;
}