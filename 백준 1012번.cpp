#include <iostream>
#include <vector>
using namespace std;

void make_input(int& vert, int& hori, int& cabbage_number) {
    cin >> vert >> hori >> cabbage_number;
}

void input_x_y(int& x, int& y) {
    cin >> x >> y;
}

vector<vector<int>> make_matrix(int vert, int hori, int cabbage_number) {
    vector<vector<int>> matrix(hori, vector<int>(vert, 0));
    int x = 0, y = 0;
    for (int i = 0; i < cabbage_number; ++i) {
        input_x_y(x, y);
        matrix[y][x] = 1;
    }
    return matrix;
}

void dfs(vector<vector<int>>& matrix, int x, int y, int vert, int hori) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    matrix[x][y] = 2;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < hori && newY >= 0 && newY < vert && matrix[newX][newY] == 1) {
            dfs(matrix, newX, newY, vert, hori); //재귀~ 재귀~
        }
    }
}

// 알고리즘 왜 안 알려줘요
// 빨리 알려달라구요 현기증 난단 말이에요

int count_groups(vector<vector<int>>& matrix, int vert, int hori) {
    int group_count = 0;
    for (int i = 0; i < hori; ++i) {
        for (int j = 0; j < vert; ++j) {
            if (matrix[i][j] == 1) {
                dfs(matrix, i, j, vert, hori);
                ++group_count;
            }
        }
    }
    return group_count;
}

int main() {
    int test_number;
    cin >> test_number;
    for (int i = 0; i < test_number; ++i) {
        int vert, hori, cabbage_number;
        make_input(vert, hori, cabbage_number);
        vector<vector<int>> matrix = make_matrix(vert, hori, cabbage_number);
        int result = count_groups(matrix, vert, hori);
        cout << result << endl;
    }
    return 0;
}

//c++에서 처음으로 해본 함수 단위로 쪼개기
//보기에는 정말 좋다
//포인터와 주소를 다루는 부분에서 복습할 부분이 많은 것 같다
