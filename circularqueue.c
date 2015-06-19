#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int front,rear;
	int capacity;
	int count;
	float *array;
}queue;

queue* createqueue(queue *qu,int cap){
	qu=malloc(sizeof *qu);
	qu->front=qu->rear=-1;
	qu->array=malloc(cap * sizeof(float));
	qu->count=0;
	qu->capacity=cap;
	printf("Queue created successfully\n");
	return qu;
}

int isfull(queue *qu){
	if(qu->capacity==qu->count)
		return 1;
	else
		return 0;
}

int isempty(queue *qu){
	return qu->count==0;
}

void enqueue(queue *qu,float val){
	if(qu->front==-1){
		//printf("first element enqueued\n");
		qu->array[++qu->front]=val;
		qu->rear=0;
		qu->count++;
	}
	
	else if(isfull(qu)!=1){
	
		if(qu->rear==qu->capacity-1)
			qu->rear=-1;
		
		qu->array[++qu->rear]=val;
		qu->count++;
		//printf("element added\n");
	}
	else if(isfull(qu)==1)
		printf("Queue is full! Enqueue unsuccessful\n");
}

float dequeue(queue *qu){
	float ret;
	if(isempty(qu))
		printf("Queue is empty! Dequeue unsuccessful!\n");
	else if(qu->front==qu->capacity-1){
		ret=qu->array[qu->front];
		qu->front=0;
		qu->count--;
	}
	else{
		ret=qu->array[qu->front];
		qu->front++;
		qu->count--;
	}
	return ret;
}

int main(void){
	queue *qu;
	int n,cont=1,ch;
	float val;
	printf("enter capacity of circular queue: ");
	scanf("%d",&n);
	qu=createqueue(qu,n);
	while(cont==1){
		printf("1. Enqueue\n2. Dequeue\n3. Check if full\n4. Check if empty\n5.Exit");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("enter data: ");
				scanf("%f",&val);
				enqueue(qu,val);
				break;
			case 2:
				val=dequeue(qu);
				printf("Dequeue element is %f\n",val);
				break;
			case 3:
				if(isfull(qu)==1)
					printf("Queue is full!\n");
				else
					printf("Not full!\n");
				break;
			case 4:
				if(isempty(qu))
					printf("Queue is empty\n");
				else
					printf("Not empty\n");
				break;
			case 5:
				cont=0;
				break;
		}
	}
	return 0;
}	
	
	

