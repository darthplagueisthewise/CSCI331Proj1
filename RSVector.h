#ifndef _RSVector_H_
#define _RSVector_H_

#include <vector>

template<class T>
class RSVector<T>
{
	private:
		
		vector<T> Container;
		std::vector<T>::iterator Active;
		std::vector<T>::iterator Passive;
		std::vector<T>::iterator Wall;

	public:

		RSVector();
		void current_heap_push(const T& item);
		void current_heap_pop();
		void pending_heap_push(const T& item);

		void Toggle();

};

#endif
