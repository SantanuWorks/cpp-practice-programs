#include <bits/stdc++.h>
using namespace std;
int stk[10];
int t;
int Pop(){
	return 0;
}
void Push(){
	
}
int top(){
	return 0;
}
bool isEmpty(){
	return false;
} 
int size(){
	return 0;
}
void display(){
	cout << endl;
	int s = t + 1;
	if( s==0 ) cout << "Stack is empty...";
	else for( int i = s-1; s >= 0; s --) cout << stk[i] << " ";
	cout << endl;
}
int main(){
	t = -1;
	display();
	return 0;
}