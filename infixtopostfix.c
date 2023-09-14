#include <stdio.h>
#define MAX 100
char stack[MAX];
int top;
int isEmpty(){ if( top+1 == 0 ) return 1; else return 0; } 
int isFull(){ if( top+1 == MAX ) return 1; else return 0; }
char peek(){ return stack[top]; }
int precedence(char ch){
	if(ch =='^') return 3;
	else if(ch =='*' || ch =='/') return 2;
	else if(ch =='+' || ch =='-') return 1;
	else return 0;
}
// return 0, associativity left to right
// return 1, associativity right to left
int associativity(char ch){
	if(ch =='^') return 1;
	else if(ch =='*' || ch =='/') return 0;
	else if(ch =='+' || ch =='-') return 0;
}
char pop(){
	if(!isEmpty()){
		char v = stack[top];
		top --;
		return v;
	}
}
void push(char ch){
	if(!isFull()){
		top ++;
		stack[top] = ch;
	}
}
void InfixToPostfix(char exp[], int n){
	for(int i = 0; i < n; i ++){
		if( !precedence(exp[i]) ) printf("%c", exp[i]);
		else if( isEmpty() ) push(exp[i]);
		else if( exp[i]==')' ){
			while( peek()!='(' ) printf("%c", pop());
			pop();
		}
		else if( peek()=='(' ) push(exp[i]);
	}
	while(isEmpty()!=1) printf("%c", pop());
}
int main(){
	top = -1;
	char exp[24] = "K+L-M*N+(O^P)*W/U/V*T+Q";
	InfixToPostfix(exp, 23);
	return 0;
}