/*�ڷᱸ�� 3���� ���� 3*/
#include <stdio.h>

struct employee
{
    char name[20];
    char num[20];
    int infm;
};

int main()
{
    struct employee man;

    printf("������ �̸� �Է�: "); scanf("%s", man.name);
    printf("�ֹε�Ϲ�ȣ �Է�: "); scanf("%s", man.num);
    printf("�޿����� �Է�: "); scanf("%d", &(man.infm));

    printf("%s, %s, %d\n", man.name, man.num, man.infm);
    
    return 0;
}