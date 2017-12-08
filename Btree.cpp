/* Btree.cpp  */

#include "Btree.h"
using namespace std;

Btree::Btree()
{
	root = nullptr;
	order = 6;
}

Btree::Btree(Node *p_nptr, int p_int)
{
	root = p_nptr;
	order = p_int;
}

Btree::~Btree()
{
	delete root;
}

void Btree::add_record(const Record& p_record)
{

}

void Btree::build_tree(vector<Record> p_vect)
{
	if (root != nullptr)
	{
		delete root;
	}

	root = new Node(p_vect);
	
	if (p_vect.size() > order)
	{
		split_node(&root);
	}
}

/* split_node public function */
/* DISCLAIMER: THIS FUNCTION MAY SPONTANEOUSLY COMBUST IF YOU TOUCH THE WRONG THING */
/* I AM PRETTY SURE THERE IS A METHOD TO MY MADNESS 								*/  
void Btree::split_node(Node *p_node)
{
	int node_size = p_node->get_vector_size();

	/* 	
		The code below does the following:
		Assume the size of the node we need to split is 17 (17 > order)
		Assuming order is equal to 6, we divide by 3
		Then "threes" will be set to 5 and "fours" will be set to 2
		After subtracting "fours" from "threes", "threes" will be set to 3
		So: threes = 3 and fours = 2
		This means that the Node needs to be split into 3 sub-nodes of size 3 and 2 sub-nodes of size 4
		4 + 4 + 3 + 3 + 3 = 17
	*/

	int threes = node_size/3; 							// Node must be at least order/2 in size
	int fours = node_size%3;							// We assume order is 6 so the 3 comes from 6/2
	threes -= fours;

	/* Threes and Fours are now set */

	//Node *temp = pnode;
	vector<Record> nodeVec = *p_node->get_record_vector();
	//*p_node = new Node();
 
 	/* We are assuming the current root is already sorted 		*/
 	/* Create however many nodes of size 4 that we need 		*/ 
	for (int i = 0; i < fours; ++i)
	{
		vector<Record> nvect;
		for (int j = 0; j < 4; ++j)							// Nodes of size 4
		{
			nvect.push_back(nodeVec.at(j));
		}

		Node *temp_ptr = new Node(nvect); 					// dynamically allocate Node so that it lives beyond the function scope => otherwise dangling pointer = badddddd

		var greatest_rec = nvect.end()-1; 					// last element (assuming sorted) in new node is greatest
		int greatest_rec_num = greatest_rec->get_num();
		string greatest_rec_str = greatest_rec->get_str();
		
		Record splitter(greatest_rec_num, greatest_rec_str, temp_ptr);
		*pnode->add_record(splitter);

		nodeVec.erase(nodeVec.begin(), nodeVec.begin()+4)
	}

	/* Create however many nodes of size 3 that we need 		*/
	for (int i = 0; i < threes; ++i)
	{
		vector<Record> nvect;
		for (int j = 0; j < 3; ++j)							// Nodes of size 3
		{
			nvect.push_back(nodeVec.at(j));
		}

		Node *temp_ptr = new Node(nvect); 					// dynamically allocate Node so that it lives beyond the function scope => otherwise dangling pointer = badddddd

		var greatest_rec = nvect.end()-1; 					// last element (assuming sorted) in new node is greatest
		int greatest_rec_num = greatest_rec->get_num();
		string greatest_rec_str = greatest_rec->get_str();
		
		Record splitter(greatest_rec_num, greatest_rec_str, temp_ptr);
		root->add_record(splitter);

		nodeVec.erase(nodeVec.begin(), nodeVec.begin()+3);
	}

	if (*6p_node->get_vector_size > order)
	{
		split_node(p_node);
	}

}






