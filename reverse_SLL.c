#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	int data;
	struct node* next;
}node;

void printlist(node*);
node* reverse(node*);

int main(){
	node* head=NULL;
	node* end;
	int i;
	printf("enter 5 elements\n");
	for(i=0;i<5;i++){
		node* temp;
		
		temp=(node*)malloc(sizeof(node));
		scanf("%d",&(temp->data));
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			end=temp;
		}
		else{
			end->next=temp;
			end=temp;
		}
	}
	//printlist(head);
	head=reverse(head);
	printf("reversed linked list is : ");
	printlist(head);
	return 0;
}

void printlist(node* head){
	node *temp=head;
	while(temp!=NULL){
		
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
}

node* reverse(node* head){
	node *temp=head, *prev=head, *curr=head->next, *newhead=NULL;
	prev->next=NULL;
	
	while(temp!=NULL){
	
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		newhead=curr;
		curr=temp;
	}
	return newhead;
}










