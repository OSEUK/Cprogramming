#include <iostream>

using namespace std;
int p[15][15] = {0,};

// 15X15 배열에 사람을 채운다.
void fill_p()
{
    for(int i = 1; i <= 14; i++){
        p[0][i] = i;
    }

    for(int i = 1; i <= 14; i++){
        for(int j = 1; j <= 14; j++){
            int k = 1;
            while(k <= j){
                p[i][j] += p[i-1][k];
                k++;
            }
        }
    }
}
// 해당 층 호수 사람 반환
int count_p(int k, int n)
{
    return p[k][n];    
}
int main(void)
{
    int T, k, n;
    cin >> T;
    int cnt[T];

    fill_p();

    for(int i = 0; i < T; i++){
        cin >> k >> n;
        cnt[i] = count_p(k, n);
    }   
    for(int i = 0; i < T; i++){
        cout << cnt[i] << endl;
    }

    return 0;
}