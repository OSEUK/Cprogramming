/* 201910903 ������ �ڷᱸ�� ���� 6-1*/
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
void MinMaxfromList(ListNode *head)
{

	element min = head->data;
	element max = head->data;
	for (ListNode *p = head; p != NULL; p = p->link){
		if(p->data < min){
			
			min = p->data;
		}
		if(p->data > max){
			max = p->data;
		}
	}
	printf("�ִ밪 : %d\n", max);
	printf("�ּҰ� : %d\n", min);
	

}
int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);

	MinMaxfromList(head);

return 0;

}

