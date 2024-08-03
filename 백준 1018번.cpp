#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct structure {
    int vert;
    int hori;
    vector<string> board;
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> parameters.vert >> parameters.hori;
    parameters.board.resize(parameters.vert);
    for (int i = 0; i < parameters.vert; ++i) {
        cin >> parameters.board[i];
    }
}

int count_repaints(const vector<string> &board, int x, int y, char first_color) {
    int repaints = 0;
    char current_color = first_color;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x + i][y + j] != current_color) {
                ++repaints;
            }
            current_color = (current_color == 'W') ? 'B' : 'W';
        }
        current_color = (current_color == 'W') ? 'B' : 'W';
    }
    return repaints;
}

int find_min_repaints(const structure &parameters) {
    int min_repaints = numeric_limits<int>::max();
    for (int i = 0; i <= parameters.vert - 8; ++i) {
        for (int j = 0; j <= parameters.hori - 8; ++j) {
            int repaints_with_w = count_repaints(parameters.board, i, j, 'W');
            int repaints_with_b = count_repaints(parameters.board, i, j, 'B');
            int repaints = min(repaints_with_w, repaints_with_b);
            min_repaints = min(min_repaints, repaints);
        }
    }
    return min_repaints;
}

int main() {
    structure parameters;
    make_input(parameters);
    int result = find_min_repaints(parameters);
    cout << result << '\n';
    return 0;
}

//문제가 처음 보인 스케일보다는 쉬움

//이중 for문을 통해 무식하게 하나하나 세고 바꾸는 방식이라 시간초과가 나지 않을까 했는데 가로, 세로의 제한이 50이라 된 것 같음.

//더 효율적인 알고리즘을 찾아보면 nlogn정도는 있지 않을까 싶음
