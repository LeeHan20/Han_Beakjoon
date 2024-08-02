#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

struct structure {
    int point_number;
    int line_number;
    int starting_point;
    vector<array<int, 2>> end_start_line;
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> parameters.point_number >> parameters.line_number >> parameters.starting_point;
    parameters.end_start_line.resize(parameters.line_number);
    for (int i = 0; i < parameters.line_number; i++) {
        cin >> parameters.end_start_line[i][0] >> parameters.end_start_line[i][1];
    }
    return;
}

void bfs(const structure &parameters, const vector<vector<int>> &graph) {
    vector<bool> visited(parameters.point_number + 1, false);
    queue<int> q;

    q.push(parameters.starting_point);
    visited[parameters.starting_point] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int adj : graph[node]) {
            if (!visited[adj]) {
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
    cout << endl;
}

void dfs_util(int node, vector<bool> &visited, const vector<vector<int>> &graph) {
    visited[node] = true;
    cout << node << " ";

    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs_util(adj, visited, graph);
        }
    }
}

void dfs(const structure &parameters, const vector<vector<int>> &graph) {
    vector<bool> visited(parameters.point_number + 1, false);
    dfs_util(parameters.starting_point, visited, graph);
    cout << endl;
}

int main() {
    structure parameters;
    make_input(parameters);

    vector<vector<int>> graph(parameters.point_number + 1);
    for (const auto &line : parameters.end_start_line) {
        int u = line[0];
        int v = line[1];
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    for (int i = 1; i <= parameters.point_number; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(parameters, graph);
    bfs(parameters, graph);

    return 0;
}

//60만원 n빵 시작

//auto를 써도 좋지만 백준을 푸는 정도의 간단한 코드에서는 자료형을 쓰는 것이 좋을 것 같다
//딱히 뭘 알기보다는 슴슴하게 bfs, dfs를 검색해보면 된다
