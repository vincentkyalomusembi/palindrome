#include <iostream>//preprocessor
using namespace std;
class animal
{
public:
	int idno;
	string pname;//class
	void eat();
	void walk();
};
class mammal: public animal
{

};
class bird: public animal
{

};
class bat: public mammal, public bird
{

};
void animal::eat()
{
	cout << "bat eating\n";//defination
};
void animal::walk()
{
	cout << "bat walking\n";
};
int main()
{
	bat b;//main
	b.walk();
	b.eat();
	return 0;
}
