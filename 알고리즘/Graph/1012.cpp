#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int field[51][51];
bool visited[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int M, N, K;

void init() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            visited[i][j] = false;
            field[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_x <= N && next_y >= 0 && next_y <= M && field[next_x][next_y] == 1 && !visited[next_x][next_y]) {
            dfs(next_x, next_y);
        }
    }
}

int main(void) {
    int T;

    cin >> T;
    int cnt[T];

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        init();

        for (int j = 0; j < K; j++) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = 1; // 지렁이의 위치를 반대로 입력받음
        }

        cnt[i] = 0;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (!visited[j][k] && field[j][k] == 1) {
                    dfs(j, k);
                    cnt[i]++;
                }
            }
        }
    }

    for (int j = 0; j < T; j++) {
        cout << cnt[j] << "\n";
    }

    return 0;
}
