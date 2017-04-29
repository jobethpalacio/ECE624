#ifndef KL_PARTITION_H
#define KL_PARTITION_H
#include <vector>
#include <string>
#include "kl_node.h"

using namespace std;
class kl_partition
{
public:
	kl_partition();
	~kl_partition();

	vector<int> nodesWithin;

};
#endif