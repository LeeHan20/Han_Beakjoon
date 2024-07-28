#include <iostream>
#include <vector>
using namespace std;

struct structure {
    int series_number;
    int sum_of_numbers;
    vector<int> series;
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> parameters.series_number >> parameters.sum_of_numbers;
    parameters.series.resize(parameters.series_number);
    for (int i = 0; i < parameters.series_number; i++) {
        cin >> parameters.series[i];
    }
    return;
}

void recursive_exploration(int index, int recent_sum, const structure &parameters, int &ans) {
    if (index == parameters.series_number) {
        if (recent_sum == parameters.sum_of_numbers) {
            ans++;
        }
        return;
    }
    recursive_exploration(index + 1, recent_sum + parameters.series[index], parameters, ans);
    recursive_exploration(index + 1, recent_sum, parameters, ans);
    //더하고 안 더하는 경우의 수 2가지를 동시에 재귀적으로 호출함
    //모든 경우의 수에 대해 재귀적으로 탐사한 후, void->return;으로 재귀를 끝냄
    return;
}

int main() {
    structure parameters;
    make_input(parameters);
    
    int ans = 0;
    recursive_exploration(0, 0, parameters, ans);
    
    if (parameters.sum_of_numbers == 0) {
        --ans;
    }

    cout << ans << '\n';
    return 0;
}

//ios::sync_with_stdio(false);
// -> c와 c++에서 scanf와 cin의 혼용 사용을 염두에 두었으나 버퍼를 공유하지 않게 동기화를 비활성화시킴
//cin.tie(nullptr);
// -> cin과 cout의 묶음을 해제하여 각각을 사용할 때 반대편의 버퍼를 플러시하지 않음

//구조체 이거 정말 물건
//입출력 스트림은 시간단축에 많이 유용함
//백터를 resize하여 list(map(int, input().split()))와 비슷한 역할을 수행할 수 있음
//재귀적 호출이 많은 경우의 수를 따질 때 매우 유용함
