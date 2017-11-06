#include "RSVector.h"
using namespace std;

RSVector::RSVector()
{
	Container = new Vector(8);
	Active = Container.begin();
	Passive = Container.end()-1;
	Wall = Container.end()-1;
	Curr_Insert_Ptr = Container.begin();
	Pass_Insert_Ptr = Container.end()-1;
}

template <class T>
void RSVector::current_heap_push(const T& item)
{
	Container.insert(Curr_Insert_Ptr, item);
	
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
