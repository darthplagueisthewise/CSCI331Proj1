#ifndef RSVector_H_
#define RSVector_H_

#include <vector>

template<class T>
class RSVector
{
	private:
		
		std::vector<T> Container;
		typename std::vector<T>::iterator Active;
		typename std::vector<T>::iterator Pending;
		typename std::vector<T>::iterator Wall;
		typename std::vector<T>::iterator Curr_Insert_Ptr;
		typename std::vector<T>::iterator Pend_Insert_Ptr;

		void Heapify();

	public:

		RSVector(int);
		void current_heap_push(const T& item);
		void current_heap_pop();
		void pending_heap_push(const T& item);

		void Toggle();

		void PrintVector();

};

#include "RSVector.cpp"

#endif
