#include "RSVector.h"
using namespace std;

RSVector::RSVector(int container_size) // Constructor with container size passed in from command line
{
	Container = new Vector(container_size);
	Active = Container.begin();
	Passive = Container.end()-1;
	Wall = Container.end()-1;
	Curr_Insert_Ptr = Container.begin();
	Pass_Insert_Ptr = Container.end()-1;
}

template <class T>
void RSVector::current_heap_push(const T& item) throw (exception)
{
	/* only add to current heap if heap location is empty */
	if (Curr_Insert_Ptr == nullptr)
	{
		Container.insert(Curr_Insert_Ptr, item);
	
		// If Insert Ptr is less than wall we increment
		if (Curr_Insert_Ptr < Wall)
		{
			++Curr_Insert_Ptr;
		}
	}
	else
	{
		throw exception("Error pushing current heap!"); 
	}
}

void RSVector::current_heap_pop()
{

}

template <class T>
void RSVector::passive_heap_push(T item)
{
	Container.insert(Pass_Insert_Ptr, item);
}

void RSVector::Toggle()
{
	
}
