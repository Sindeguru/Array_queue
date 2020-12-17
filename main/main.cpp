#include <iostream>
#include "listarray.h"
using namespace std;

int main()
{
	TListArray<char> A(10);

	A.InsFirst('a');
	A.InsLast('b');
	A.InsFirst('c');

	TListArrayIterator<char> i = d.begin();

	while (i.IsGoNext())
	{
		cout << i.GetData();
		i.GoNext();
	}

	return 0;
}