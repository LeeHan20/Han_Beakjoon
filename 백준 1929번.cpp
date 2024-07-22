#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // n = 3;
    // m = 16;
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

// endl을 쓰는 것과 "\n"을 쓰는 것은 출력이 많을 때 성능 차이를 많이 유발한다. 
// endl이 보기에는 깔끔하지만 웬만하면 "\n"을 권장함.
