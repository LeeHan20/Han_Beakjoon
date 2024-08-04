#include <iostream>
#include <vector>
using namespace std;

void make_input(int &n) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
}

long long count_pinary_numbers(int n) {
    if (n == 1) return 1; 

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    make_input(n);
    long long result = count_pinary_numbers(n);
    cout << result << '\n';
    return 0;
}

//어떤 친구가 매일 말하던 dp
//아 dp하고 싶다~, 이거 dp로 푸는 건가?

//전 값이 계속 물리고 물리는 모습이 인상적이다
