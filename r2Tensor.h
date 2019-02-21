#ifndef R2TENSOR_H
#define R2TENSOR_H

#include <cstdlib>
#include <vector>

typedef std::vector<std::vector<int>> r2Vec;

class r2Tensor
{
public:
	r2Tensor(std::size_t x, std::size_t y);
	r2TensorPopulated(std::size_t x, std::size_t y);
	~r2Tensor();
	void changeAtPosition(std::size_t x, std::size_t y, int val);
	
	r2Tensor addR2Tensor(const r2Tensor* TensorToAdd);
	r2Tensor multR2Tensor(const r2Tensor* TensorToAdd);
	void printTensor();
	
private:
 r2Vec r2Vector;
 void initVector(std::size_t x, std::size_t y);
 void populateVetor();
};

#endif // R2TENSOR_H
