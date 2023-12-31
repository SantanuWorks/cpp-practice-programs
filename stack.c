#include <stdio.h>
#define MAX_SIZE 10
int stk[MAX_SIZE];
int top;
int size(){
	return top+1;
}
int isEmpty(){
	if(!size()) return 1;
	else return 0;
} 
int isFull(){
	if(size()==MAX_SIZE) return 1;
	else return 0;
}
void pop(){
	if(isEmpty()) printf("\nStack is empty...\n");
	else{
		printf("\n%d is popped!\n", stk[top]);
		top --;
	}
}
void push(int n){
	if(isFull()) printf("\nStack is full...\n");
	else{
		top ++;
		stk[top] = n;
		printf("\n%d is pushed!\n", stk[top]);
	}
}
void display(){
	printf("\n");
	if(isEmpty()) printf("Stack is empty...");
	else for( int i = top; i >= 0; i --) printf("%d ", stk[i]);
	printf("\n");
}
int topElement(){
	return stk[top];
}
int main(){
	top = -1;
	int ch = 1;
	for(; ch != 4 ;){
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nChoose the operation: ");
		scanf("%d", &ch);
	}
	return 0;
}