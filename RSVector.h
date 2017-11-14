#ifndef RSVector_H_
#define RSVector_H_

#include <vector>
#include <fstream>

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

		std::string inputFileName;	/** File name to read data from */
		std::string iRecord;		/** String to hold input record */
		std::string runFileName;	/** Name of file to hold runs */
		std::string lastPopped;		/** Keeps track of last popped item */

		std::ifstream inFile;		/** File to read in data from */
		std::ofstream runFile;		/** File to hold runs */

		char iRecordPiece;			/** Character to hold input record piece */

		int Recor

	public:

		RSVector(int);							/** Constructor for replacement selection vector */
		void current_heap_push(const T& item);	/** Pushes item onto active heap */
		void current_heap_pop();				/** Pops off root of active heap */
		void pending_heap_push(const T& item);	/** Pushes item onto pending heap */
		void toggle();							/** Toggle active and pending heaps, and ends run */
		void print_vector();					/** Prints contents of the container vector */
		void heapify(int choice);				/** Makes a given subset of the vector a min heap */
		void rs_sort();							/** Directs the replacement selection sort */
		void finish();							/** Closes files when program is finished */

};

#include "RSVector.cpp"

#endif
