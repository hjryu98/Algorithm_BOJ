#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
map <string, int> m;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char str[12];
		cin >> str;
		int size = strlen(str);
		
		sort(str, str + size);

		string tmp = "";

		for (int j = 0; j < size; j++) {
			tmp += str[j];
		}
		m[tmp]++;
	}
	cout << m.size();
	

	return 0;
}