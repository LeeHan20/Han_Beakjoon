#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <tuple>
#include <array>
#include <queue>
using namespace std;

struct structure {
    int number_leak_point;
    int tape_lenth;
    array<bool, 1000> leak_points = {false};
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> parameters.number_leak_point >> parameters.tape_lenth;
    int index;
    for (int i = 0; i < parameters.number_leak_point; i++) {
        cin >> index;
        parameters.leak_points[index - 1] = true;
    }
    return;
}

void taping(structure &parameters, int &taping_number) {
    for (int i = 0; i < 1000; ++i) {
        if (parameters.leak_points[i]) {
            taping_number++;
            for (int j = 0; j < parameters.tape_lenth && i + j < 1000; ++j) {
                    parameters.leak_points[i + j] = false;
            }
        }
    }
    return;
}

int main() {
    structure parameters;
    make_input(parameters);
    
    int taping_number = 0;
    taping(parameters, taping_number);
    
    cout << taping_number << "\n";
    return 0;
}

//길이의 최댓값이 크지 않으면 가변적인 백터보다는 그렇지 않은 배열을 사용해서 전체를 순회하는 방법이 코드 쓰기 더 편함

//이렇게 순회해야 하는 문제는 백터의 resize보다 bool타입의 배열이 더 좋은 듯

//if 문에 들어갈 때도 가독성 상승
