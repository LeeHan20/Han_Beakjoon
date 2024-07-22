#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> arr(m + 1, 1);
    arr[0] = arr[1] = 0;

    for (int i = 2; i <= sqrt(m); i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= m; j += i) {
                arr[j] = 0;
            }
        }
    }

    for (int i = n; i <= m; i++) {
        if (arr[i] == 1) {
            cout << i << endl;
        }
    }
    return 0;
}
