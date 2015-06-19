/*Print postfix expression of inputted infix expression*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
	int top;
	int capacity;
	int *array;
}stack;

stack* createstack(char *);
void push(stack* ,int );
int isempty(stack *);
int pop(stack *st);
int peek(stack *st);
int precedence(char c);

int main(){
	char exp[100];
	char post[100];
	int k=-1;
	stack *st;
	int i=0,p=0;
	printf("enter string expression: ");
	//gets(exp); 
	//fgets(exp, sizeof(exp), stdin);
	scanf("%s",exp);
	printf("Infix expression : %s",exp);
	st=createstack(exp);
	
	for(i=0;i<strlen(exp);i++){
		if( (exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z'))
			post[++k]=exp[i];
		else if(exp[i]=='(')
			push(st,exp[i]);
		else if(exp[i]==')'){
			while(!isempty(st) && peek(st)!='(')
				post[++k]=pop(st);
			pop(st);
		}
		else{
			while(precedence(exp[i]) < precedence(peek(st)))
				post[++k]=pop(st);
			push(st,exp[i]);
		}
	}
	while(!isempty(st))
		post[++k]=pop(st);
	
	post[++k]='\0';
	printf("Postfix expression :\n%s\n",post);
	return 0;
		
}

stack* createstack(char *exp){
	stack* st;
	st=malloc(sizeof *st); //casting malloc is unnecessary and sizeof is not a function!
	st->top=-1;
	st->capacity=strlen(exp);
	st->array=(int*)malloc(st->capacity * sizeof(int));
	printf("Stack created successfully\n");
	return st;
}

void push(stack* st,int val){
	st->array[++st->top]=val;
}

int isempty(stack *st){
	return st->top==-1;
}

int pop(stack *st){
	return st->array[st->top--];
}

int peek(stack *st){
	return st->array[st->top];
}

int precedence(char c){
	switch(c){
		case '(':
			return 0;
			break;
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
			
		case '^':
			return 3;
			break;
	}
}		

			

				
