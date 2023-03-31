/*자료구조 3주차 과제 1*/
#include <stdio.h>
#define ROW 5
#define COL 5
int main()
{
    int score[ROW][COL]={0};        //5*5배열 0으로 초기화

    for(int i=0;i<ROW-1;i++)
    {
        for(int j=0;j<COL-1;j++)
        {
            printf("%d친구의 %d점수",i+1,j+1);      
            scanf("%d", &score[i][j]);              //점수의 합 제외 4*4만큼 입력받기
        }
    }
    for(int k=0;k<ROW-1;k++){
        score[ROW-1][k] = score[0][k] + score[1][k] + score[2][k] + score[3][k];        //각 행마다 총합
    }
    for(int l=0;l<COL-1;l++){
        score[l][COL-1] = score[l][0] + score[l][1] + score[l][2] + score[l][3];        //각 열마다 총합
    }
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
           printf("%5d",score[i][j]);
        }
        printf("\n");                       //출력
    }
    return 0;
}