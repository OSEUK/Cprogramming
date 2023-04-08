/* 201910903 ������ �ڷᱸ�� ���� 6-2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, int value)
{
       ListNode *p =
              (ListNode *)malloc(sizeof(ListNode)); //(1)

       p->data = value;		  //(2)
       p->link = head;		  //(3)
       head = p;                     	  //(4)

       return head;
}
// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
     ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)

     p->data = value;		//(2)
     p->link = pre->link;	//(3)	
     pre->link = p;		//(4)	

     return head;		//(5)	
}
ListNode* delete_first(ListNode *head)
{
     ListNode *removed;
     if (head == NULL) 
                 return NULL;
     
     removed = head;	// (1)
     head = removed->link;	// (2)
     free(removed);		// (3)
     
     return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_pre(ListNode *head, ListNode *pre)
{
	ListNode * removed;
	removed = pre->link;                            // (1)
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			
}
void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("NULL \n");
}
// �׽�Ʈ ���α׷�
ListNode* delete_node(ListNode *head, element value)
{
    ListNode *pre= NULL;
    ListNode *p = head;
    while( p != NULL){
        if(p->data == value){
            if(pre == NULL){   //�ݺ����� ���� ó�� ���̸�
                head = p->link;    // p->link�� head�� ����.
                free(p);        
                return head;
            }
            p = pre->link;            
            pre->link = p->link;
            free(p);
            return head;
        }
        pre = p;    //p�� ���� ���� ���� �� �ܰ踦 pre�� ���ܵ�.
        p = p->link;
    }
	return NULL;
}
int main(void)
{
    ListNode* head = NULL;
    element value;              // value ����
    head = insert_first(head, 10);
    head = insert_first(head, 13);
    head = insert_first(head, 8);
    head = insert_first(head, 33);
    head = insert_first(head, 21);
    print_list(head);

    printf("������ ���� �Է��Ͻÿ�: ");
    scanf_s("%d", &value);

    head = delete_node(head, value);
    print_list(head);

    return 0;
}
