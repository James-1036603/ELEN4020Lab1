#ifndef R2TENSOR_H
#define R2TENSOR_H

#include <cstdlib>
#include <vector>
#include <iostream>
#include "ErrorLog.h"

typedef std::vector<std::vector<int>> r2Vec;
static ErrorLog r2ErrorLogger;

class r2Tensor
{
public:
    r2Tensor() {};
	r2Tensor(std::size_t x, std::size_t y, const bool populated);	
	~r2Tensor() {};
	void changeAtPosition(std::size_t x, std::size_t y, int val);
	
	r2Tensor addR2Tensor(const r2Tensor* TensorToAdd);
	r2Tensor multR2Tensor(const r2Tensor* TensorToMult);
	void printTensor();
	
private:
 r2Vec r2Vector;
 void initVector(std::size_t x, std::size_t y);
 void populateVetor();
 
};

#endif // R2TENSOR_H
