#include <iostream>

using namespace std;
long long result[1001] = {0,};

// 시간 복잡도를 줄이기 위해 재귀 함수에서 반복문으로 변환
int fill_tile(int n)
{
    result[1] = 1;
    result[2] = 2;
    for(int i = 3; i <= n ; i++){
        result[i] = result[i-1] + result[i-2];
        result[i] = result[i] % 10007;
    }

    return result[n]; 
}

int main(void)
{
    int n;

    cin >> n;

    cout << fill_tile(n) << endl;

}