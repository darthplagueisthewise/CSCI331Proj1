#include "RSVector.h"
#include <iostream>
#include <algorithm>

using namespace std;

struct greater1{
  bool operator()(const long& a,const long& b) const{
    return a>b;
  }
};

template <class T>
RSVector<T>::RSVector(int container_size) // Constructor with container size passed in from command line
{
	Container = vector<T>(container_size);
	Active = Container.begin();
	Pending = Container.end()-1;
	Wall = Container.end()-1;
	Curr_Insert_Ptr = Container.begin();
	Pend_Insert_Ptr = Container.end()-1;
}

template <class T>
void RSVector<T>::current_heap_push(const T& item)
{
	*Curr_Insert_Ptr = item;
	
	// Heapify();
	
	// If Insert Ptr is not at wall we increment
	if (Curr_Insert_Ptr != Wall)
	{
		Curr_Insert_Ptr++;
	}
}

template <class T>
void RSVector<T>::current_heap_pop()
{
	pop_heap(Container.begin(),Container.end(), greater1());
}

template <class T>
void RSVector<T>::pending_heap_push(const T& item)
{
	*Pend_Insert_Ptr = item;

	/* 	Needs to be more code added here 
		Moving wall over?
		Worry about this later
	*/
}

template <class T>
void RSVector<T>::Toggle()
{
	auto temp = Active;
	Active = Pending;
	Pending = temp;
}

template <class T>
void RSVector<T>::PrintVector()
{
	for (T item : Container)
	{
		cout << item << " ";
	}

	
	cout << endl;
}

template <class T>
void RSVector<T>::Heapify()
{
	make_heap(Container.begin(), Container.end(), greater1());
	
	/*while (Container.size()) {
		pop_heap(Container.begin(),Container.end(), greater1());
		long min = Container.back();
		Container.pop_back();  
		cout << min << std::endl;
  	}*/

}
