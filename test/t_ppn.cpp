// t_ppn.cpp
// module test of [ppn]
// within namespace xcm
#include <iostream>
#include "../xc/mdl/ppn.hpp"

using namespace std;
using namespace xc;

int main()
{
	mdl::ppn mac;
	int dim = 2;
	int spl = 6;
	mac.set_has_bias(false);
	mac.set_pattern_dim(dim);
	mac.set_sample_size(spl);
	mac.set_stop_error(0.1);
	mac.set_learning_rate(0.1);
	mac.set_max_iter(200);
	// set input and output
	// demo: f(x,y)=2x+3y;
	// f(0,0)=0
	// f(0,1)=3
	// f(1,0)=2
	// f(1,1)=5
	// f(1,2)=7
	// f(2,2)=10
	double ** in = new double*[spl];
	for(int i=0; i<spl; i++)
		in[i] = new double[dim];
	double * out = new double[spl];

	in[0][0]=0;in[0][1]=0;out[0]=0;
	in[1][0]=0;in[1][1]=1;out[1]=3;
	in[2][0]=1;in[2][0]=0;out[2]=2;
	in[3][0]=1;in[3][0]=1;out[3]=5;
	in[4][0]=1;in[4][1]=2;out[4]=7;
	in[5][0]=2;in[5][1]=2;out[5]=10;

	// set weight vector
	double * w = new double[dim];
	for(int i=0; i<dim; i++)
		w[i] = 0;
	
	mac.in = in;
	mac.out = out;
	mac.w = w;
	mac.train();
	
	cout<<"MACHINE ERROR: "<<mac.get_current_error()<<endl;
	cout<<"MACHINE WEIGHT: "<<"["<<mac.w[0]<<","
		<<mac.w[1]<<","<<mac.b<<"]"<<endl;
	
	for(int i=0; i<spl; i++)
		delete [] (double*)(in[i]);
	delete [] in;
	delete [] out;
	delete [] w;

	return 0;
}


