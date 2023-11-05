#include <iostream>

using namespace std;
int count = 0;

int Findrc(int N, int row, int col){

    if(N == 1)
        return 0;

    // divide (총 4등분)
    int size = N / 2;

    // conquer
    if(row < size && col < size)
        return Findrc(size, row, col);
    else if(row < size && col >= size)
        return Findrc(size, row, col - size) + size*size;
    else if(row >= size && col < size)
        return Findrc(size, row - size, col) + 2*size*size;
    else    
        return Findrc(size, row - size, col - size) + 3*size*size;
}

int main(void)
{
    int N, row, col;

    cin >> N >> row >> col;

    // 1을 N번만큼 비트이동하여 2^N * 2^N에서 탐색
    int size = (1 << N);

    cout << Findrc(size, row, col);
    
    return 0;
}