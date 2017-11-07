#include "RSVector.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
	int Vect_Size = atoi(argv[1]);
	
	RSVector<int> testObj(Vect_Size);
	
	int testArray[] = {2,3,7,4,1,9,6,8};
	
	for (int i = 0; i < Vect_Size; ++i)	
	{
		testObj.current_heap_push(testArray[i]);
	}

	testObj.PrintVector();

	return 0;

}
