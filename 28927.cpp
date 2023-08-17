#include<iostream>
using namespace std;
int sum1, sum2;
int a, b, c, d, e, f;
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    sum1 = 3 * a + 20 * b + 120 * c;
    sum2 = 3 * d + 20 * e + 120 * f;
    if (sum1 == sum2) cout << "Draw";
    else if (sum1 > sum2) cout << "Max";
    else cout << "Mel";


    return 0;
}