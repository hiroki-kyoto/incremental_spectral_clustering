// t_vect.cpp
// object of vector test class
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);

	cout<<data.size()<<endl;
	data.clear();
	data.erase(data.begin(), data.end());
	cout<<data.size()<<endl;

	return 0;
}
