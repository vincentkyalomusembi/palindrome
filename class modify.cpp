#include <iostream>//preprocessor
using namespace std;
class person
{
public:
	int idno;
	void getdata()
	{
		cout << "Enter idno";
			 cin >> idno;
	}
	string pname;//class
	void eat();
	void walk();
};
class student: public person
{
public:
	string regno;
	void enroll(string pg);
};
void person::eat()
{
	cout << pname << " person eating\n"; //defination
}
void person::walk()
{
	cout << pname << " person walking\n";
}
void student::enroll(string pg)
{
	cout << regno << " is taking " << pg;
}
int main()
{
	student p;//main
	p.getdata();
	p.pname = "vincent";
	p.regno = "1234";
	p.eat();
	p.walk();
	p.enroll("BCS");
	return 0;
}
