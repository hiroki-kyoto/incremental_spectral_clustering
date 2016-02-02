// ann.hpp
// class definition of artificial intelligence
#include <iostream>
#include <fstream>
#include <vector>

namespace xc
{
namespace mdl
{

using namespace std;
const bool ON = true;
const bool OFF = false;
// define node state
enum NODE_STATE
{
	ACTIVE = 0,
	SLEEP = 1,
	DEAD = 2,
};

enum MODEL_STATE
{
	SAFE = 0,
	FAST = 1,
};

// point pair to store information describing graphs
struct conn
{
	int head; // neuron id of head
	int tail; // neuron id of tail
	char direction; // forward:f;backward:b;double:d;
	double weight; // weight for this
};


template <class T>
class ann
{
private:
	vector<T> nodes; // all neurons
	vector<conn> graph; // graph for model 
	MODEL_STATE ms; // safe or fast
public:
	ann();
	~ann();
	void addConn();
	void delConn();
	void run(); // run the model 
	void check(); // check if the model is legal
	void report(); // report information about this model
	void debug(bool on_off); // switch on or off

};

ann::ann()
{
	// reset the node list
	nodes.erase(nodes.begin(), nodes.end());
	// reset connection list
	graph.erase(graph.begin(), graph.end());
}

ann::~ann()
{
	// reset the node list
	nodes.erase(nodes.begin(), nodes.end());
	// reset connection list
	graph.erase(graph.begin(), graph.end());
}

void ann::addConn(int begin, int end, char direction, double weight)
{
	if(
	// check if connection is validated
	if(c.begin<0||c.end<0||c.begin>=nodes.size()||
			c.end>=nodes.size())
	{
		cout<<"CONNECTION ADDING FAILURE: BEGIN OR END INDEX ARE OUT OF RANGE."<<endl;
		return;
	}
	// search for connections existence
	
}


};
};
