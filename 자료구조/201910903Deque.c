/*201910903 ������ �ڷᱸ�� 5���� ����*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 50
typedef char element;	// ����ü�� data[]�� ���ڿ��� �����ϱ� ����.
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ 
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ����ť ��� �Լ�
void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%c ", q->data[i]);	//���ڷ� ����ϱ� ���� %c�� ����
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// ���� �Լ�
void add_rear(DequeType *q, element item)        // enqueue(QueueType *q, element item)
{
	if (is_full(q)) {
		error("���� ��ȭ�����Դϴ�");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_front(DequeType *q)                 // dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("���� ��������Դϴ�");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element get_front(DequeType *q)
{
	if (is_empty(q)) {
		error("���� ��������Դϴ�");
		exit(1);
	}

	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(DequeType *q)
{
	if (is_empty(q)) {
		error(" ���� ��������Դϴ�");
		exit(1);
	}

	return q->data[q->rear];
}
void add_front(DequeType *q, element val)
{
	if (is_full(q)) {
		error("���� ��ȭ�����Դϴ�");
		return;
	}

	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�");
		exit(1);
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}



int main()
{
    
    bool flag = true;	//flag�� true or false �˻�
    DequeType queue;	//����ü queue����
	char a[] = "eye";	//���ڿ��� �˻��� �迭 ����
	
	init_deque(&queue);	 //queue->data�迭 �ʱ�ȭ
    deque_print(&queue); //����Ʈ
	
	int len = sizeof(a)/sizeof(char)-1;
    
	for(int i=0; i < len ;i++)	//���ڿ� �������� null�� �ԷµǾ��ֱ� ������ -1�Ͽ� �Էµ� ���ڿ��� ũ�� �˻�
	{
	add_rear(&queue, a[i]);		//����
    deque_print(&queue);
	}

    while(flag == true)		//flag�� true�϶� �ݺ�
	{
        char a = delete_front(&queue);	//�տ��� �� �� a�� ����
        char b = delete_rear(&queue);	//�ڿ��� �� �� b�� ����
        deque_print(&queue);
        len -= 2;	//�յڿ��� 2�� ������ -2
        if(a != b){		//a�� b�� �ٸ��� 
            flag = false;	//flag�� false�� �����Ͽ�
            break;		//�ݺ��� Ż��
		}
        if(len <= 1)	//���ڿ� ���̰� 1�� ���Ͽ���
            break;		//Ż��
    }
    if (flag == false)	//flag�� false�� �Ǹ�
	{	
		for(int i=0;i<sizeof(a)/sizeof(char)-1; i++)
		{
        printf("%c",a[i]);		//���ڿ� ���
		}
		printf("�� ȸ���� �ƴմϴ�.\n");	//a[]�� ȸ���� �ƴմϴ�.
    }
    else if (flag == true)	// ȸ���̶��
	{
		for(int j=0; j<sizeof(a)/sizeof(char)-1; j++)
		{
			printf("%c",a[j]);
		}printf("�� ȸ���Դϴ�.\n");
	}
    return 0;
}   