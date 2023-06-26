#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1002][1002]; // dp[i][j]: 1번째 문자열의 i번째, 2번째 문자열의 j번째 까지의 최소거리
string a, b;
int lena, lenb;
int main() {
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();

	for (int i = 0; i <= lena; i++) dp[i][0] = i;
	for (int i = 0; i <= lenb; i++) dp[0][i] = i;

	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	cout << dp[lena][lenb];


	return 0;
}