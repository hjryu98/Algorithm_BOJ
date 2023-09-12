#include <iostream>
#include <string>
using namespace std;
string cur = "DKSH";
string str;
int cnt;
int main() {
    cin >> str;
    if (str.find(cur) == string::npos) cnt = 0;
    else {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'D') {
                int ans = 0;
                for (int j = 1; j < 4; j++) {
                    if (str[i + j] != cur[j]) break;
                    else ans++;
                }
                if (ans == 3) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}