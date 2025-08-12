#include<stdio.h>
#define MAX 5
typedef struct queue{
	int arr[MAX];
	int front;
	int rear;
	
}queue;

void createqueue(queue *q){
	q->front=-1;
	q->rear=-1;
	
}
int isFull(queue *q){
	return (q->front==q->rear+1 || (q->front==0&&q->rear==MAX-1));
	
}
int isEmpty(queue *q){
	return q->front==-1;
	
}
void enqueue(queue *q,int item){
	if(isFull(q)){
		printf("Queue Full\n");
		return ; 
	}
	if(q->rear==-1){
		q->front=q->rear=0;
		q->arr[q->rear]=item;
	}
	else if(q->front==0 && q->rear==MAX-1){
		q->rear=0;
		q->arr[q->rear]=item;
	}
	else{
		q->arr[++q->rear]=item;
	}
}

int dequeue(queue *q){
	if(isEmpty(q)){
		printf("Queue Empty \n");
		return 0;
	}
	int data =q->arr[q->front];
	if(q->rear==q->front)
	q->rear=q->front=-1;
	else if(q->front==MAX-1)
			q->front=0;
	else
	q->front++;
	return data;
}
int peek(queue *q){
	if(isEmpty(q)){
		printf("Queue Empty \n ");
		return 0;
	}
	return q->arr[q->front];
}
int main(){
	queue q;
	createqueue(&q);
	int k,elem;
	do{
		printf("Enter 1 for enqueue \n2 for dequeue \n3 for peek \n4 for exit \n");
		scanf("%d",&k);
		switch(k){
			case 1: 
				printf("Enter the element to push\n");
				scanf("%d",&elem);
				enqueue(&q,elem);
				break;
			case 2:
				printf("Element dequeued is %d\n",dequeue(&q));
				break;
			case 3:
				printf("The element is %d\n",peek(&q));
				break;
			case 4:
				printf("Exiting.....\n");
				break;
			default : 
				printf("Wrong choice selected\n");
				break;			
		}
	}while(k!=4);
	return 0;
}