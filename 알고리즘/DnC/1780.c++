#include <iostream>

using namespace std;
int paper_count[3] = {0}; // -1, 0, 1
int arr[2200][2200];

bool CheckSame(int num , int row, int col)
{
    int start = arr[row][col];

    // arr[row][col] 부터 num*num 크기의 행렬의 요소 비교 
    for(int i = row; i < row + num; i++){
        for(int j = col; j < col + num; j++){
            if(arr[i][j] != start)
                return false;
        }
    }
    return true;
}
void CalCount(int num, int row, int col)
{
    // 3으로 나누어 행과 열 총 9개로 분할
    int size = num / 3;

    // 전부 같으면 카운트 증가
    if(CheckSame(num, row, col))
        paper_count[(arr[row][col] + 1)]++;

    // 다른게 있으면 9개로 분할하여 체크
    else
    {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                CalCount(size, row + (size * i),  col + (size * j));
            }
        }
    }
}
int main(void)
{   
    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++){
            cin >> arr[i][j];
        }
    }
    CalCount(num, 0, 0);
    
    for(int i = 0; i < 3; i++){
        cout << paper_count[i] << endl;
    }

}