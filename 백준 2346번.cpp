#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct structure {
    int ballon_number;
    vector<int> array_ballons;
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> parameters.ballon_number;
    parameters.array_ballons.resize(parameters.ballon_number); 
    for (int i = 0; i < parameters.ballon_number; ++i) {
        cin >> parameters.array_ballons[i];
    }
    
    return;
}

void find_ballons_array(structure &parameters) {
    deque<pair<int, int>> balloons; 
    for (int i = 0; i < parameters.ballon_number; ++i) {
        balloons.push_back({i + 1, parameters.array_ballons[i]});
    }

    while (!balloons.empty()) {
        cout << balloons.front().first << " ";
        int move = balloons.front().second;
        balloons.pop_front();
        
        if (balloons.empty()) break; 

        if (move > 0) {
            for (int i = 0; i < move - 1; ++i) {
                balloons.push_back(balloons.front());
                balloons.pop_front();
            }
        } else {
            for (int i = 0; i < abs(move); ++i) {
                balloons.push_front(balloons.back());
                balloons.pop_back();
            }
        }
    }
}

int main() {
    structure parameters;
    make_input(parameters);
    find_ballons_array(parameters);
    
    return 0;
}

//pop과 push를 vector를 이용해서 해도 상관은 없지만 deque를 이용할 때보다 성능이 떨어질 수 있으니 deque를 그냥 include하는 것이 좋음

//utility에 좋은 것들이 많아 보임
//파이썬에서 자료형에 상관없이 튜플로 저장했던 것을 pair가 c++에서 실현 가능하게 만들어 줌
//접근 방법도 매우 편리한 편
