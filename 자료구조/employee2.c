/*자료구조 3주차 과제 4*/
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
        printf("종업원 이름 입력: "); scanf("%s", man[i].name);             //반복문,배열로 3명의 정보 받기
        printf("주민등록번호 입력: "); scanf("%s", man[i].num);
        printf("급여정보 입력: "); scanf("%d", &(man[i].infm));
    }
    printf("\n");
    for (int i=0;i<people;i++){
    printf("%s, %s, %d\n", man[i].name, man[i].num, man[i].infm);          //3명의 정보 순서대로 출력
    }
    return 0;
}