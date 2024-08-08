#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> process_commands(const string &commands) {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    
    int x = 0, y = 0;
    int dir = 0; // 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽

    int min_x = 0, max_x = 0, min_y = 0, max_y = 0;

    for (char command : commands) {
        if (command == 'F') {
            x += dx[dir];
            y += dy[dir];
        } else if (command == 'B') {
            x -= dx[dir];
            y -= dy[dir];
        } else if (command == 'L') {
            dir = (dir + 3) % 4; 
        } else if (command == 'R') {
            dir = (dir + 1) % 4; 
        }
        
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    return {max_x - min_x, max_y - min_y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    vector<string> commands(T);

    for (int i = 0; i < T; ++i) {
        cin >> commands[i];
    }

    for (const string &command : commands) {
        pair<int, int> result = process_commands(command);
        int area = result.first * result.second;
        cout << area << "\n";
    }

    return 0;
}

//좌표평면 다루기 기초

//directioin과 dx, dy를 설정하고 x, y 각각의 변수에 현재 위치를 저장
//여기서 직사각형의 유무과 관계없이 각 방향의 최댓값을 영역으로 인정해주니 각 방향의 최댓값만을 구하면 됨
//도형이 만들어져야 한다는 조건이 있었으면 훨씬 까다로웠을 것

//때에 따라 구조체를 쓰면 훨씬 복잡해진다
