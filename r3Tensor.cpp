#include "r3Tensor.h"

r3Tensor::r3Tensor(int x, int y, int z, bool populate)
{
	for(std::size_t i = 0; i < z; i++)
	{
		r3Vector.push_back(r2Tensor(x,y,populate));
	}
}

void r3Tensor::printTensor()
{
	for(std::size_t i = 0; i < this->r3Vector.size(); i++) 
	{
		this->r3Vector.at(i).printTensor();
		std::cout<<std::endl;
	}
}

r3Tensor r3Tensor::rank3TensorAdd(const r3Tensor* TensorToAdd)
{//Adds two r3 tensors together. Check that they have the same dimensions. (other 2 are already checked in other method)
	r3Tensor tempR3Tensor;
    r2Tensor tempR2Tensor;
	if(this->r3Vector.size() == TensorToAdd->r3Vector.size())
	{
		for(std::size_t i = 0; i < this->r3Vector.size(); i++) 
		{
			tempR2Tensor = r3Vector.at(i).rank2TensorAdd(&TensorToAdd->r3Vector.at(i));
            tempR3Tensor.addr2TensorToVector(&tempR2Tensor);
		}
	} else r3ErrorLogger.logError("Error: Dimension mismatch for adding 3D Matrix.");
    return tempR3Tensor;
    
}

void r3Tensor::addr2TensorToVector(const r2Tensor* TensorToAdd)
{//Private method to add a r2 tensor to the r3 tensor. This is a function used in the addition and multiplication
	this->r3Vector.push_back(*TensorToAdd);
}

r3Tensor r3Tensor::rank3TensorMult(const r3Tensor* TensorToMult)
{//Multiply two nxn r3 Tensors
	r3Tensor tempR3Tensor;
	r2Tensor tempR2Tensor;
	if(this->r3Vector.size() == TensorToMult->r3Vector.size())
	{
		for(std::size_t i = 0; i < this->r3Vector.size(); i++)
		{
			tempR2Tensor = this->r3Vector.at(i).rank2TensorMult(&TensorToMult->r3Vector.at(i));
			tempR3Tensor.r3Vector.push_back(tempR2Tensor);
		}
		
	} else r3ErrorLogger.logError("Error: Dimension mismatch for multiplying 3D Matrix.");
	
	return tempR3Tensor;
}