#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5    // MAX_QUEUE_SIZE 5�� ������
typedef int element;        // �������� element
typedef struct{
    element data[MAX_QUEUE_SIZE];   // ť �迭 data ����
    int front, rear;
}QueueType;     
void error(const char *message)     // error�޽��� ����
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(QueueType *q)       // ť �ʱ�ȭ
{
    q->front = q->rear = 0;
}
int is_empty(QueueType *q)          // ť�� ����� ��
{
    return (q->front == q->rear);   // front�� rear�� ������
}
int is_full(QueueType *q)           // ť�� ���� á�� ��
{
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);  // rear+1�� MAX�� ���� �������� front�� ���� ��
}
void queue_print(QueueType *q)      // ť�� ����Ʈ ��.
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);    // ť�� ���� ����

    if (!is_empty(q)){          // ť�� ������� �ʴٸ�
        int i = q->front;       // front���� i�� ����
        do{
            i = (i+1) % (MAX_QUEUE_SIZE);   //front+1�� MAX�� ���� ������ i�� ����
            printf("%d��",q->data[i]);      //data[i] ���
            if(i == q->rear)                //i�� rear�� ���� ���ٸ�
                break;                  
        }while (i != q->front);             //front�� ���� i�� ����������.
    }
    printf("\n");   
}
void enqueue(QueueType *q, element item)      // ������ ����
{
    if (is_full(q)){
        error("ť�� ��ȭ�����Դϴ�.");
        return;
    }
    
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;     //rear�� ���� rear+1�� MAX�� ���� ��.
    q->data[q->rear] = item;                    //data[rear]�� item�� ����
}

element dequeue(QueueType *q)           // ������ �̱� 
{
    if(is_empty(q)){
        error("ť�� ��������Դϴ�.");
        exit(1);
    }
    q->front =(q->front+1) % MAX_QUEUE_SIZE;    // front+1���� MAX�� ���� ���� front���
    return q->data[q->front];                   

}
int main(void)
{
	QueueType queue;        // ����ü ���� queue����
	int element;            

	init_queue(&queue);     // ť �ʱ�ȭ
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue))    // ť�� full�� �ƴ� ����
	{
		printf("������ �Է��Ͻÿ�: ");  
		scanf("%d", &element);      //element�� �Է�
		enqueue(&queue, element);   //q*�� element�� �Է�
		queue_print(&queue);        // print
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
	return 0;
}




