#include <iostream>
using namespace std;
int main()
{
	int array[10] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 6};
	int i;
	int j = 0;
	int n = 10;
	for(i = 0; i < n; i++)
	{
		if(array[i] != array[i + 1])
		{
			array[j] = array[i];
			j++;// Increment `j` to point to the next position for a unique element.
		}
		else
		{
			array[j] = array[n - 1];// Place the unique element at the `j`-th position.
		}
	}
	for(i = 0; i < j; i++)
	{
		cout << array[i] << "";
	}
	return j; // Return the new length of the array, which is the number of unique elements.
}

