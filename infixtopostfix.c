#include <stdio.h>
#define MAX 100
char stack[MAX];
int top;
int precedence(char ch){
	if(ch =='(' || ch ==')') return 4;
	else if(ch =='^') return 3;
	else if(ch =='*' || ch =='/') return 2;
	else if(ch =='+' || ch =='-') return 1;
	else return 0;
}
// return 0, associativity left to right
// return 1, associativity right to left
int associativity(char ch){
	if(ch =='(' || ch ==')') return 0;
	else if(ch =='^') return 1;
	else if(ch =='*' || ch =='/') return 0;
	else if(ch =='+' || ch =='-') return 0;
}
int isEmpty(){
	if(top==-1) return 1;
	else return 0;
} 
int isFull(){
	if(top==MAX-1) return 1;
	else return 0;
}
char pop(){
	if(isEmpty()) printf("\nStack is empty...\n");
	else{
		char v = stack[top];
		top --;
		return v;
	}
}
void push(char ch){
	if(isFull()) printf("\nStack is full...\n");
	else{
		top ++;
		stack[top] = ch;
	}
}
char peek(){
	return stack[top];
}
void InfixToPostfix(char exp[], int n){
	for(int i = 0; i < 9; i ++){
		if( precedence(exp[i])==0 ) printf("%c", exp[i]);
		else if( exp[i]=='(' || isEmpty()==1 || peek()=='(' || (precedence(peek()) < precedence(exp[i])) ) 
			push(exp[i]);
		else if( exp[i]==')' ){
			char v;
			while( (v=pop())!='(' ) 
				if( v!='(' || v!=')' ) 
					printf("%c", v);
		}
		else if( precedence(peek()) > precedence(exp[i]) ) 
			while( precedence(exp[i]) < precedence(peek()) ) 
				printf("%c", pop());
		else{
			if( associativity(exp[i])==0 ){
				printf("%c", pop());
				push(exp[i]);
			}
			else push(exp[i]);
		}
	}
	while(isEmpty()!=1) printf("%c", pop());
}
int main(){
	top = -1;
	char exp[24] = "K+L-M*N+(O^P)*W/U/V*T+Q";
	InfixToPostfix(exp, 23);
	return 0;
}