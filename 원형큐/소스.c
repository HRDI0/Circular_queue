#include <stdio.h>
#include <stdlib.h>

//============���� ť �ڵ� ����
#define MAX_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;

}Qtype;

//���� ���
void error(char* messege) {
	fprintf(stderr, "%s\n", messege);
	exit(1);
}
//������·� �ʱ�ȭ
void init_queue(Qtype *q) {
	q->front = q->rear = 0;
}

//������� �˻�
int is_empty(Qtype *q) {
	return(q->front == q->rear);
}
//��ȭ ���� �˻�
int is_full(Qtype* q) {
	return ((q->rear + 1) % MAX_SIZE == q->front);
}
//���� ť ���
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

//���� �Լ�
void enq(Qtype* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�."); 

		q->rear = (q->rear + 1) % MAX_SIZE;
		q->data[q->rear] = item;
}

//���� �Լ�
element deq(Qtype * q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

//ī��Ʈ �Լ�
int get_count(Qtype *q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	return ((q->rear)-(q->front));
	
}
//===========���� ť �ڵ� ��

int main() {
	Qtype the_Q; 
	init_queue(&the_Q);
	int i = 0;
	int a[3] = { 1,2,3 };
	for (i = 0; i < 3; i++) {
		enq(&the_Q, a[i]);
	}
	queue_print(&the_Q);
	printf("ť�� �����ϴ� ����� ������ %d�� �̴�.\n",get_count(&the_Q));
}