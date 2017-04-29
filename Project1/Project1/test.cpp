#include "kl_node.h"
#include "kl_partition.h"
#include <iostream>


using namespace std;


int main()
{
	const int SIZE_OF_TABLE = 10;
	kl_partition A;
	kl_partition B;
	vector<kl_node*> nodeTable;

	//make a table of nodes
	for (size_t i = 0; i < SIZE_OF_TABLE; i++)
	{
		kl_node *node = new kl_node();
		node->id = i;
		nodeTable.push_back(node);
	}

	//randomly add edges
	//(1) pick a node
	for (size_t i = 0; i < SIZE_OF_TABLE; i++)
	{

		//(2) pick a node it may connect to
		for (size_t j = 0; j < SIZE_OF_TABLE; j++)
		{	
			if (j != i)
			{
				if (rand() % SIZE_OF_TABLE-1 == 0) //chance of connectivity arbitrary
				{
					//if it picks a node, then that node picks it
					nodeTable[i]->connectedWithNode.push_back(j);
					nodeTable[j]->connectedWithNode.push_back(i);
				}
			}
		}
	}

	//randomly partition
	for (size_t i = 0; i < SIZE_OF_TABLE; i++)
	{
		if (rand() % 2 == 0)
		{
			A.nodesWithin.push_back(i);
		}
		else
		{
			B.nodesWithin.push_back(i);
		}
	}
	cout << "CONTENTS OF PARTITION A" << endl;
	for (size_t i = 0; i < SIZE_OF_TABLE/2; i++)
	{
		cout << A.nodesWithin[i] << endl;
	}
	

	for (size_t i = 0; i < SIZE_OF_TABLE; i++)
	{
		cout << "Connected With Node Size: " << nodeTable[i]->connectedWithNode.size() << endl;
		for (size_t j = 0; j < nodeTable[i]->connectedWithNode.size(); j++)
		{
			cout << "Node " << i << ": " << nodeTable[i]->connectedWithNode[j] << endl;
		}
	}


	for (size_t i = 0; i < SIZE_OF_TABLE; i++)
	{
		delete nodeTable[i];
	}
	
	cin.get();


}

