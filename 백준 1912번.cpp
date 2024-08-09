#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_input(int &n, vector<int> &sequence) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    sequence.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
}

int max_subarray_sum(int n, vector<int> &sequence) {
    vector<int> dp(n);
    dp[0] = sequence[0];
    int max_sum = dp[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = max(sequence[i], dp[i - 1] + sequence[i]);
        max_sum = max(max_sum, dp[i]);
    }

    return max_sum;
}

int main() {
    int n;
    vector<int> sequence;
    make_input(n, sequence);
    
    int result = max_subarray_sum(n, sequence);
    cout << result << "\n";
    
    return 0;
}

//dp~ dp~

//1182번 부분수열의 합 문제처럼 재귀적 탐사를 통한 방법으로도 해결이 가능할 것 같다.
