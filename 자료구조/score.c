/*�ڷᱸ�� 3���� ���� 1*/
#include <stdio.h>
#define ROW 5
#define COL 5
int main()
{
    int score[ROW][COL]={0};        //5*5�迭 0���� �ʱ�ȭ

    for(int i=0;i<ROW-1;i++)
    {
        for(int j=0;j<COL-1;j++)
        {
            printf("%dģ���� %d����",i+1,j+1);      
            scanf("%d", &score[i][j]);              //������ �� ���� 4*4��ŭ �Է¹ޱ�
        }
    }
    for(int k=0;k<ROW-1;k++){
        score[ROW-1][k] = score[0][k] + score[1][k] + score[2][k] + score[3][k];        //�� �ึ�� ����
    }
    for(int l=0;l<COL-1;l++){
        score[l][COL-1] = score[l][0] + score[l][1] + score[l][2] + score[l][3];        //�� ������ ����
    }
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
           printf("%5d",score[i][j]);
        }
        printf("\n");                       //���
    }
    return 0;
}