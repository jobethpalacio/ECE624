#ifndef KL_NODE_H
#define KL_NODE_H
#include <vector>
#include <string>

using namespace std;
class kl_node
{
public:
	kl_node();
	~kl_node();
	int id;
	string index;
	vector<int> connectedWithNode;
	bool lock;

};

#endif