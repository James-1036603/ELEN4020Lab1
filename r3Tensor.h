#ifndef R3TENSOR_H
#define R3TENSOR_H
#include <vector>
#include "r2Tensor.h"
class r3Tensor
{
public:
	r3Tensor(int x, int y, int z, bool populate);	
	~r3Tensor() {};	
	r3Tensor multR3Tensor(const r3Tensor* TensorToMult);
	r3Tensor addR3Tensor(const r3Tensor* TensorToAdd);
	void printTensor();
	
private:
	std::vector<r2Tensor> r3Vector; //The r3Tensor is a accumulation of r2Tensors
	void addr2TensorToVector(const r2Tensor* TensorToAdd);
};

#endif // R3TENSOR_H
