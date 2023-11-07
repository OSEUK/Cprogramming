#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> map[100001];
int parent[100001];
bool visited[100001];

void dfs(int vertex){
    visited[vertex] = true;
    for(int i = 0 ; i < map[vertex].size() ; i++){
        int vn = map[vertex][i];
        if(!visited[vn]){
            parent[vn] = vertex;
            dfs(vn);
        }
    }
}

int main(void){
    int N, a, b;

    cin >> N;

    for(int i = 0; i < N-1; i++){
        cin >> a >> b ;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++){
        cout << parent[i] << "\n";  // endl 사용시 시간초과 (why)
    }
}