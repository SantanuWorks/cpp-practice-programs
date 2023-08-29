#include <stdio.h>
int stk[10];
int top;
int pop(){
	return 0;
}
void push(int n){
	
}
int isEmpty(){
	if( top==-1 ) return 1;
	else return 0;
} 
int siz(){
	return 0;
}
void display(){
	printf("\n");
	int s = top + 1;
	if( s==0 ) 	printf("Stack is empty...");
	else for( int i = s-1; s >= 0; s --) printf("%d ", stk[i]);
	printf("\n");
}
int main(){
	top = -1;
	display();
	return 0;
}