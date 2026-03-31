#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;

const int MAX = 1001; // 정점의 개수 N은 최대 1,000
vector<int> adj[MAX];   
bool visited_dfs[MAX];
bool visited_bfs[MAX];

// DFS 함수 (재귀 방식)
void dfs(int node) {
    visited_dfs[node] = true; // 간곳이라는 표시
    cout << node << " "; //출력

    for (int i = 0; i < adj[node].size(); i++) { // 현재 노드의 간선들을 모두 확인
        int next = adj[node][i];
        if (!visited_dfs[next]) { // false 일 경우 못감
            dfs(next);
        }
    }
}

// BFS 함수 (큐 방식)
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited_bfs[start] = true;// 간곳이라는 표시
    
        
    int size=0;

    while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; i++) { // q에 저장된 갯수 만큼 반복
            cout << q.front() << " "; //출력
            for (int j = 0; j < adj[q.front()].size(); j++) { // 저장 된 노드의 연결된 갯수 만큼 반복
                if (!visited_bfs[adj[q.front()][j]]) {
                    q.push(adj[q.front()][j]); // 연결 된 노드 push
                    visited_bfs[adj[q.front()][j]] = true; //방문 했다는걸 표시
                }
                
            }
            q.pop();
        }
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    // 간선 정보 입력받기
    for (int i = 0; i < m; i++) {
        int u, w;
        cin >> u >> w;
        // 양방향 간선이므로 양쪽에 추가
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // 내림차순을 통해서 정렬하기
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // DFS 실행 및 결과 출력
    dfs(v);
    cout << "\n";

    // BFS 실행 및 결과 출력
    bfs(v);
    cout << "\n";

    return 0;
}