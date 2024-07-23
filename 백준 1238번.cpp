#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

const int INF = 1e9+7;
vector<pii> graph[2][1001]; 
vector<int> dist[2];
int N, M, X;

void input() {
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        graph[0][u].emplace_back(t, v);
        graph[1][v].emplace_back(t, u);
    }
    dist[0].assign(N + 1, INF);
    dist[1].assign(N + 1, INF);
}

void dijkstra(int k) {
    dist[k][X] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, X);

    while (!pq.empty()) {
        auto [min_cost, now] = pq.top(); pq.pop();
        if (min_cost > dist[k][now]) continue;
        
        for (auto [cost, next] : graph[k][now]) {
            int next_cost = min_cost + cost;
            if (next_cost < dist[k][next]) {
                dist[k][next] = next_cost;
                pq.emplace(next_cost, next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    input();
    
    // 정점들에서 X로 가는 최단거리
    dijkstra(1);
    
    // X에서 정점들로 가는 최단거리
    dijkstra(0);
    
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        res = max(res, dist[0][i] + dist[1][i]);
    }
    
    cout << res;
    
    return 0;
}
