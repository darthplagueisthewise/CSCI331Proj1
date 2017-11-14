#include "RSVector.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct greater1
{
	bool operator()(const string& a,const string& b) const
	{
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
	
	if (Curr_Insert_Ptr != Wall)	// If Insert Ptr is not at wall we increment
	{	
		Curr_Insert_Ptr++;	
	}

	for(int j = 0; j < Container.size(); j++)
	{
		std::cout << "CHP: " << j << " "  << Container.at(j) << std::endl;
	}
    heapify(1);		// Heapify with 1 is for the active heap
}

template <class T>
void RSVector<T>::current_heap_pop()
{
	runFile << *Active;
	lastPopped = *Active;	// Store last popped for comparison
	if (Curr_Insert_Ptr != Wall)
	{
		*Active = *(Curr_Insert_Ptr - 1);
		Curr_Insert_Ptr--;
	}
	heapify();
}

template <class T>
void RSVector<T>::pending_heap_push(const T& item)
{
	if(*(Container.end() -1) != 0 && Wall != Container.begin())
	{
		Wall--;
		Pend_Insert_Ptr--;
		*Pend_Insert_Ptr = item;
		heapify(2); 		// Heapify with 2 is for the pending heap	
	}
	else if ((Container.end() -1) == 0)
	{
		*Pend_Insert_ptr = item;
	}
	else
	{
		cout << "Wall cannot be moved!"
	}
}

template <class T>
void RSVector<T>::toggle()
{
	auto temp = Active;
	Active = Pending;
	Pending = temp;
}

template <class T>
void RSVector<T>::print_vector()
{
	for (T item : Container)
	{
		cout << item << " ";
	}
	cout << endl;
}

template <class T>
void RSVector<T>::heapify(int choice)
{
	if(choice == 1)
		make_heap(Active, Curr_Insert_Ptr, greater1());		// For active heap
	else if(choice == 2)
		make_heap(Pending, Wall, greater1());				// For pending heap

	/*for(int j = 0; j < Container.size(); j++)
	{
		cout << "In heapify: " << j << " "  << Container.at(j) << endl;
	}*/
}

template <class T>
void RSVector<T>::rs_sort()
{
	lastPopped = " ";	// Initialize to ' ' so wall won't be moved on first comparisons
	
	// Store input file name
	cout << "What is the name of the file you would like to read in?" << endl;
	cin >> inputFileName;
	inFile.open(inputFileName.c_str());

	cout << "Output file: " << endl;
	cin >> runFileName;
	runFile.open(runFileName.c_str());
	
	if(inFile.is_open())
	{
		while(inFile >> iRecordPiece)	// Run until all records have been read in
		{
			if(iRecordPiece != ',')		// Build the record, one char at a time up to ','
			{
				iRecord += iRecordPiece;
			}
			else						// Do everything else once record is built
			{
				if(iRecord < lastPopped)	// If current record is < last popped record, 
				{							// push it onto the pending heap
					cout << "To pending" << endl;
					pending_heap_push(iRecord);
				}
				else						// If current record > last popped record, 
				{							// push it onto the active heap
					current_heap_push(iRecord);
				}
				iRecord.clear();			// Clear the string 
			}	// end else
		}		// end while
	}			// end if
	inFile.close();
}

template <class T>
void RSVector<T>::finish()
{
	runFile.close();
}

