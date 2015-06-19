#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

typedef struct queue{
	node *front,*rear;
	int count;
	int capacity;
}queue;

queue* createqueue(queue *qu,int cap){
	qu=malloc(sizeof *qu);
	qu->capacity=cap;
	qu->front=qu->rear=NULL;
	qu->count=0;
	return qu;
}

void enqueue(queue* qu,int val){
	node *temp=malloc(sizeof *temp);
	temp->data=val;
	temp->next=NULL;
	
	if(qu->front==NULL){
		qu->front=qu->rear=temp;
		qu->count=1;
	}
	else if(!isfull(qu)){
		qu->rear->next=temp;
		qu->rear=temp;
		qu->count++;
	}
}

int dequeue(queue* qu){
	int ret=-1;
	if(!isempty(qu)){
		if(qu->count==1){
			ret=qu->front->data;
			free(qu->front);
			qu->front=qu->rear=NULL;
			qu->count=0;
		}
		else{
			ret=qu->front->data;
			node *temp=qu->front;
			qu->front=qu->front->next;
			
			free(temp);
			qu->count--;
		}
		return ret;
	}
	
	return -1;
}

int isempty(queue* qu){
	if(qu->count==0)
		return 1;
	else
		return 0;
}

int isfull(queue* qu){
	if(qu->count == qu->capacity)
		return 1;
	else
		return 0;
}
	

int main(void){
	int n,go_on=1,val;
	queue *qu;
	qu=createqueue(qu,100);
	while(go_on==1){
		printf("1. Enqueue\n2. Dequeue\n3. Check if full\n4. Check if empty\n5. Exit\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				
				printf("enter data: ");
				scanf("%d",&val);
				enqueue(qu,val);
				break;
			case 2:
				val=dequeue(qu);
				if(val==-1)
					printf("Queue is empty!\n");
				else
					printf("dequeue element: %d\n",val);
				break;
			case 3:
				if(isfull(qu))
					printf("Full!\n");
				else
					printf("Not Full!\n");
				break;
			case 4:
				if(isempty(qu))
					printf("Empty!\n");
				else
					printf("Not Empty!\n");
				break;
			case 5:
				go_on=0;
				break;
			default:
				printf("enter valid choice\n");
		}
	}
	return 0;
}


				
