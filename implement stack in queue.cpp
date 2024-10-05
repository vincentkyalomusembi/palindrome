#include<iostream> 
#include<queue> 
using namespace std; 
queue<int>q;
void push (int digit)// function to push a digit into the stack using queue
{
	int size=q.size();
	q.push(digit);
	for(int i=0;i<size;i++)
	{
		int temp=q.front();
		q.pop();
		q.push(temp);
	}
}
int pop()
{
	if (q.empty())
	{
		cout<<"stack underflow\n";
		return-1;
	}
	else
	{
		int poppeddigit=q.front();
		q.pop();
		return poppeddigit;
	}
}
int main()
{
	int number;
	cout<<"Enter a number:";//input  the number
	cin>>number;
	while(number!=0)//push each digit of the number onto the stack
	{
		int digit=number%10;
		push(digit);
		number=number/10;
	}
	cout<<"Digit popped from the stack:";
	while(!q.empty())
	{
		cout<<pop()<<"";
	}
	cout <<endl;
	return 0;
}