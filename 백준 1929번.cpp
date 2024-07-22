#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> decimal(m + 1, 1);
    decimal[0] = decimal[1] = 0;
    for (int i = 2; i <= sqrt(m); i++) {
        if (decimal[i] == 1) {
            for (int j = i * i; j <= m; j += i) {
                decimal[j] = 0;
            }
        }
    }
    for (int i = n; i <= m; i++) {
        if (decimal[i] == 1) {
            cout << i << '\n';
        }
    }
    return 0;
}
