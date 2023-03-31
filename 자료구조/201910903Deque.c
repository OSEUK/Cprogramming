/*201910903 오세욱 자료구조 5주차 과제*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 50
typedef char element;	// 구조체의 data[]를 문자열로 구성하기 위함.
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(DequeType *q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%c ", q->data[i]);	//문자로 출력하기 위해 %c로 변경
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// 삽입 함수
void add_rear(DequeType *q, element item)        // enqueue(QueueType *q, element item)
{
	if (is_full(q)) {
		error("덱이 포화상태입니다");
		return;
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType *q)                 // dequeue(QueueType *q)
{
	if (is_empty(q)) {
		error("덱이 공백상태입니다");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element get_front(DequeType *q)
{
	if (is_empty(q)) {
		error("덱이 공백상태입니다");
		exit(1);
	}

	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(DequeType *q)
{
	if (is_empty(q)) {
		error(" 덱이 공백상태입니다");
		exit(1);
	}

	return q->data[q->rear];
}
void add_front(DequeType *q, element val)
{
	if (is_full(q)) {
		error("덱이 포화상태입니다");
		return;
	}

	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if (is_empty(q)) {
		error("큐가 공백상태입니다");
		exit(1);
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}



int main()
{
    
    bool flag = true;	//flag로 true or false 검사
    DequeType queue;	//구조체 queue정의
	char a[] = "eye";	//문자열을 검사할 배열 설정
	
	init_deque(&queue);	 //queue->data배열 초기화
    deque_print(&queue); //프린트
	
	int len = sizeof(a)/sizeof(char)-1;
    
	for(int i=0; i < len ;i++)	//문자열 마지막엔 null이 입력되어있기 때문에 -1하여 입력된 문자열의 크기 검사
	{
	add_rear(&queue, a[i]);		//삽입
    deque_print(&queue);
	}

    while(flag == true)		//flag가 true일때 반복
	{
        char a = delete_front(&queue);	//앞에서 뺀 값 a에 대입
        char b = delete_rear(&queue);	//뒤에서 뺀 값 b에 대입
        deque_print(&queue);
        len -= 2;	//앞뒤에서 2개 뺐으니 -2
        if(a != b){		//a와 b가 다르면 
            flag = false;	//flag에 false를 대입하여
            break;		//반복문 탈출
		}
        if(len <= 1)	//문자열 길이가 1개 이하여도
            break;		//탈출
    }
    if (flag == false)	//flag가 false로 되면
	{	
		for(int i=0;i<sizeof(a)/sizeof(char)-1; i++)
		{
        printf("%c",a[i]);		//문자열 출력
		}
		printf("는 회문이 아닙니다.\n");	//a[]는 회문이 아닙니다.
    }
    else if (flag == true)	// 회문이라면
	{
		for(int j=0; j<sizeof(a)/sizeof(char)-1; j++)
		{
			printf("%c",a[j]);
		}printf("는 회문입니다.\n");
	}
    return 0;
}   