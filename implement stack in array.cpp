#include<iostream>
using namespace std;
#define MAX 5
int stack_array[MAX];
int top = -1;
void push(int data)
{
	if(top == MAX - 1)
	{

		cout << "stack overflow\n";
		return  ;//end of push function
	}
	top = top + 1;
	stack_array[top] = data;
}
int pop()
{
	int value;
	if(top == -1)
	{
		cout << "stack underflow\n"; //abnormal termination of program
	}
	value = stack_array[top];
	top = top - 1;
	return value;//end of pop function
}
void print()
{
	int i;
	if(top == -1)
	{
		cout << "stack unerflow\n";
		return;
	}
	for (i = top; i >= 0; i--)
		cout << stack_array[i];
}
int main()
{
	int data , i;
	push (1);
	push (2);
	push (3);
	push (4);
	data = pop();
	print();
	return 0;
}
