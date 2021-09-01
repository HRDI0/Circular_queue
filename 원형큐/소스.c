#include <stdio.h>
#include <stdlib.h>

//============원형 큐 코드 시작
#define MAX_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;

}Qtype;

//오류 출력
void error(char* messege) {
	fprintf(stderr, "%s\n", messege);
	exit(1);
}
//공백상태로 초기화
void init_queue(Qtype *q) {
	q->front = q->rear = 0;
}

//공백상태 검사
int is_empty(Qtype *q) {
	return(q->front == q->rear);
}
//포화 상태 검사
int is_full(Qtype* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}
//원형 큐 출력
void queue_print(Qtype* q) {
	printf("Queue(fornt = %d rear = %d)\n", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_SIZE;
			printf(" %d | ", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입 함수
void enq(Qtype* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다."); 

		q->rear = (q->rear + 1) % MAX_SIZE;
		q->data[q->rear] = item;
}

//삭제 함수
element deq(Qtype * q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//카운트 함수
int get_count(Qtype *q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	if (is_full(q))
		error("큐가 포화상태입니다.");
	return ((q->rear)-(q->front));
	
}
//===========원형 큐 코드 끝

int main() {
	Qtype the_Q; 
	init_queue(&the_Q);
	int i = 0;
	int a[3] = { 1,2,3 };
	for (i = 0; i < 3; i++) {
		enq(&the_Q, a[i]);
	}
	queue_print(&the_Q);
	printf("큐에 존재하는 요소의 개수는 %d개 이다.\n",get_count(&the_Q));
}