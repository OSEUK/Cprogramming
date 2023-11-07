#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool visited[10000];
vector<int> map[1001];

// visited 초기화
void initVisit(){
    for(int i = 0; i < 1001; i++){
        visited[i] = false;
    }
}

// dfs
void dfs(int vertex){

    visited[vertex] = true;
    cout << vertex << " ";

    for(int i = 0 ; i < map[vertex].size() ; i++){
        int vn = map[vertex][i];
        if(!visited[vn])
            dfs(vn);
    }
}

// bfs
void bfs(int vertex){

    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i = 0; i < map[x].size(); i++){
            int vn = map[x][i];
            if(!visited[vn]){
                q.push(vn);
                visited[vn] = true;
            }
        }
    }
}

int main(void){

    int N, M, V;
    int a, b;
    cin >> N >> M >> V ;

    for(int i = 0; i < M; i++){
        cin >> a >> b; 
        map[a].push_back(b);
        map[b].push_back(a);
    }

     for (int i = 1; i <= N; i++) {
        sort(map[i].begin(), map[i].end());
    }

    dfs(V);
    cout << endl;
    initVisit();
    
    bfs(V);
}