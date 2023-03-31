/*자료구조 3주차 과제 3*/
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

    printf("종업원 이름 입력: "); scanf("%s", man.name);
    printf("주민등록번호 입력: "); scanf("%s", man.num);
    printf("급여정보 입력: "); scanf("%d", &(man.infm));

    printf("%s, %s, %d\n", man.name, man.num, man.infm);
    
    return 0;
}