/*�ڷᱸ�� 3���� ���� 4*/
#include <stdio.h>
#define people 3
struct employee
{
    char name[20];
    char num[20];
    int infm;
};

int main()
{
    struct employee man[people];
    for(int i=0;i<people;i++){
        printf("������ �̸� �Է�: "); scanf("%s", man[i].name);             //�ݺ���,�迭�� 3���� ���� �ޱ�
        printf("�ֹε�Ϲ�ȣ �Է�: "); scanf("%s", man[i].num);
        printf("�޿����� �Է�: "); scanf("%d", &(man[i].infm));
    }
    printf("\n");
    for (int i=0;i<people;i++){
    printf("%s, %s, %d\n", man[i].name, man[i].num, man[i].infm);          //3���� ���� ������� ���
    }
    return 0;
}