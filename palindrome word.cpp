#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char string[20];
    int w,length,mix=0;
    cout<<"Enter any string"<<endl;
    cin>>string;
    length=strlen(string);
    for(w=0;w<length;w++);
    {
		if(string[w]!=string[length-w-1])
		{
			mix=1;
		}
	}
	if(mix)
	{
		cout<<string<<"Entered string is not a palindrome"<<endl;
	}
	else
	{
		cout<<string<<"Entered string is a palindrome"<<endl;
	}
    return 0;
}