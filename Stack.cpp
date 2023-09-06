#include <bits/stdc++.h>
#define MAX 10
using namespace std;
class Stack{
	int arr[MAX];
	int top;
	public:
	Stack(){ top = -1; }
	void push(int);
	void pop();
	void display();
	bool isFull();
	bool isEmpty();
	int size();
	void topElement();
};
int Stack::size(){
	return top+1;	
}
void Stack::push(int n){
	cout << endl;	
	if(isFull()) cout << "Stack is full!";
	else{
		top ++; 
		arr[top] = n;
		cout << n << " is pushed!";
	}
	cout << endl;	
}
void Stack::pop(){
	cout << endl;	
	if(isEmpty()) cout << "Stack is empty!";
	else{
		cout << arr[top] << " is popped!";
		top --;
	}
	cout << endl;	
}
void Stack::display(){
	cout << endl;		
	if(isEmpty()) cout << "Stack is empty!";
	else{
		for(int i = size()-1; i >= 0; i --){
			cout << arr[i] << " ";
		}
	}
	cout << endl;	
}
bool Stack::isFull(){
	if(size()==MAX) return true;
	else return false;
}
bool Stack::isEmpty(){
	if(size()==0) return true;
	else return false;
}
void Stack::topElement(){
	cout << endl << "top element is " << arr[top] << endl;
}
int main(){
	Stack stk;
	stk.display();
	stk.push(12);
	stk.push(56);
	stk.push(32);
	stk.topElement();
	stk.push(64);
	stk.push(86);
	stk.display();
	stk.pop();
	stk.topElement();
	stk.pop();
	stk.display();
	stk.pop();
	stk.topElement();
	stk.pop();
	stk.display();
	stk.push(43);
	stk.topElement();
	stk.push(17);
	stk.display();
	return 0;
}