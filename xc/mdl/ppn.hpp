// ppn.hpp
// perceptron model definition
#ifndef MODEL_PERCEPTRON
#define MODEL_PERCEPTRON
#include <iostream>
#include <vector>
#include <cmath>
/* namespace : xiangchao model */
namespace xc
{
namespace mdl
{
using namespace std;
// class body
class ppn
{
private:
	int dim; // dimension of pattern
	int spl; // count of sample set
	int max_iter; // the max iteration times
	double stop_error; // error level of stop-machine condition
	double learning_rate; // learning rate to decrease error
	double error; // error level of current loop
	int system_state; // system state =[0,1-4,5];
	bool has_bias; // if has bias or not
	// 0:none set; 1-4:not fully set;>=5:fully set;
public:
	ppn();
	~ppn();
	double ** in; // input of system
	double * out; // output of system
	double * w; // weight of connections
	double b; // bias of machine
	void set_has_bias(bool has_bias);
	void set_pattern_dim(int dim);
	void set_sample_size(int size);
	void set_max_iter(int max_iter);
	void set_stop_error(double error);
	void set_learning_rate(double learning_rate);
	double get_current_error();
	void train(); // train with sample input and output 
	void predict(); // predict outcomes with given input
};

ppn::ppn()
{
	max_iter = 100;
	stop_error = 0.01;
	learning_rate = 0.5;
	system_state = 0;
	has_bias = true;
	error = 0.0;
	dim = 0;
	spl = 0;
	in = NULL;
	out = NULL;
	w = NULL;
	b = 0.0;
}

ppn::~ppn()
{
	// do nothing
}

void ppn::set_pattern_dim(int dim)
{
	ppn::dim = dim;
	system_state ++;
}

void ppn::set_sample_size(int size)
{
	ppn::spl = size;
	system_state ++;
}

void ppn::set_max_iter(int max_iter)
{
	ppn::max_iter = max_iter;
	system_state ++;
}

void ppn::set_stop_error(double error)
{
	ppn::stop_error = error;
	system_state ++;
}

void ppn::set_learning_rate(double learning_rate)
{
	ppn::learning_rate = learning_rate;
	system_state ++;
}

double ppn::get_current_error()
{
	return sqrt(error);
}

void ppn::set_has_bias(bool has_bias)
{
	ppn::has_bias = has_bias;
	system_state ++;
}

void ppn::train()
{
	if(system_state<6||(!in)||(!out)||(!w))
	{
		cout<<"MODEL NOT WELL SET!"<<endl;
		return;
	}	

	// allocate weight vector based on input data
	// that is argument [dim]
	for(int i=0; i<max_iter; i++)
	{
		// reset system state
		error = 0.0;
		
		// continue with another loop of training on dataset
		for(int j=0; j<spl; j++)
		{
			double dif = 0.0;
			double sum = 0.0;
			for(int k=0; k<dim; k++)
				sum += w[k]*in[j][k];
			if(has_bias)
				sum += b;
			// calculate the final outcome
			dif = out[j]-sum;
			
			// adjustment	
			for(int k=0; k<dim; k++)
				w[k] += dif*learning_rate*in[j][k];
			if(has_bias)
				b += dif*learning_rate;
			error += dif*dif;
			//learning_rate = max(1e-3,learning_rate-1e-3);
		}

		error = error/spl;
		if(error<stop_error*stop_error)
			break; // model ready
		cout<<error<<endl;
	}
}

void ppn::predict()
{
	if(system_state<6)
	{
		cout<<"MODEL NOT READY FOR PREDICTION!"<<endl;
		return;
	}

	for(int i=0; i<spl; i++)
	{
		double sum = 0.0;
		for(int j=0; j<dim; j++)
			sum +=  w[j]*in[i][j];
		out[i] = sum;
		if(has_bias)
			out[i] += b;
	}

	cout<<"PREDICTION RESULT CAN BE OBTAINED THRU [PERCEPTRON.OUT]."<<endl;
}

};
};

#endif

