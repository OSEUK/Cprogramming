/*자료구조 3주차 과제 2*/
#include <stdio.h>
#define ROW 3
#define COL 3
int main()
{
    int A[ROW][COL] = {
        {1, 3, 5},
        {6, 7, 8},
        {9, 2, 1},
    } ;
    int B[ROW][COL] = {
        {1, 3, 8},
        {6, 7, 6},
        {9, 2, 2}
    };
    int C[ROW][COL] = {0};      //새로운 갑을 넣을 3*3배열 C 초기화

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            C[i][j] = A[i][j] + B[i][j];        //값 입력과 함께 
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}