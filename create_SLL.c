#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}node;

node* create_singlylinkedlist(node*,int);
void display(node*);

int main(){
	int n,val,flag=0;
	node* head=NULL;
	
	
	while(flag!=1){
		printf("Choose:\n1. Add element\n2. Exit\n3. Print Linked List\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter element value\n");
				scanf("%d",&val);
				head=create_singlylinkedlist(head,val);
				break;
			case 2:
				flag=1;
				break;
			case 3:
				display(head);
				break;
			default:
				printf("enter valid choice\n");
		}
	}
	return 0;
}

node* create_singlylinkedlist(node* head,int val){
	node* ptr;
	if(head==NULL){
		ptr=(node*)malloc(sizeof(node));
		ptr->next=NULL;
		ptr->data=val;
		return ptr;
	}
	else{
		ptr=head;
		node* headptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		node* temp=(node*)malloc(sizeof(node));
		
		temp->next=NULL;
		temp->data=val;
		ptr->next=temp;
		return headptr;
	}
}	
	
void display(node* head){
	node* temp=head;
	if(head==NULL)
		printf("Empty LL\n");
	else{
		printf("Elements are:\n");
		while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}

	}
}
