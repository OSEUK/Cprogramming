#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5    // MAX_QUEUE_SIZE 5로 정ㅇ의
typedef int element;        // 전역변수 element
typedef struct{
    element data[MAX_QUEUE_SIZE];   // 큐 배열 data 정의
    int front, rear;
}QueueType;     
void error(const char *message)     // error메시지 변수
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
void init_queue(QueueType *q)       // 큐 초기화
{
    q->front = q->rear = 0;
}
int is_empty(QueueType *q)          // 큐가 비었을 때
{
    return (q->front == q->rear);   // front와 rear가 같으면
}
int is_full(QueueType *q)           // 큐가 가득 찼을 때
{
    return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);  // rear+1을 MAX로 나눈 나머지와 front가 같을 때
}
void queue_print(QueueType *q)      // 큐를 프린트 함.
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);    // 큐의 현재 상태

    if (!is_empty(q)){          // 큐가 비어있지 않다면
        int i = q->front;       // front값을 i에 대입
        do{
            i = (i+1) % (MAX_QUEUE_SIZE);   //front+1을 MAX로 나눈 나머지 i에 대입
            printf("%dㅣ",q->data[i]);      //data[i] 출력
            if(i == q->rear)                //i와 rear의 값이 같다면
                break;                  
        }while (i != q->front);             //front의 값이 i와 같을때까지.
    }
    printf("\n");   
}
void enqueue(QueueType *q, element item)      // 데이터 삽입
{
    if (is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;     //rear의 값은 rear+1을 MAX로 나눈 값.
    q->data[q->rear] = item;                    //data[rear]에 item을 삽입
}

element dequeue(QueueType *q)           // 데이터 뽑기 
{
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        exit(1);
    }
    q->front =(q->front+1) % MAX_QUEUE_SIZE;    // front+1값을 MAX로 나눈 값이 front라면
    return q->data[q->front];                   

}
int main(void)
{
	QueueType queue;        // 구조체 변수 queue정의
	int element;            

	init_queue(&queue);     // 큐 초기화
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue))    // 큐가 full이 아닌 동안
	{
		printf("정수를 입력하시오: ");  
		scanf("%d", &element);      //element값 입력
		enqueue(&queue, element);   //q*에 element값 입력
		queue_print(&queue);        // print
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}




