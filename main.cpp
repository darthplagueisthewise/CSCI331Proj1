#include "RSVector.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	int Vect_Size = 8; //atoi(argv[1]);
	RSVector<string> testObj(Vect_Size);

	testObj.rs_sort();
	
	/* Testing 
	int testArray[] = {2,10,7,4,1,9,11,8};
	
	for (int i = 0; i < Vect_Size; ++i)	
	{
		std::cout << "Pushing: " << testArray[i] << std::endl;
		testObj.current_heap_push(testArray[i]);
	}*/

	//testObj.PrintVector();

	return 0;
}
