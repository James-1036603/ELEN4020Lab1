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

r3Tensor r3Tensor::addR3Tensor(const r3Tensor* TensorToAdd)
{//Adds two r3 tensors together. Check that they have the same dimensions. (other 2 are already checked in other method)
	r3Tensor tempR3Tensor;
    r2Tensor tempR2Tensor;
	if(this->r3Vector.size() == TensorToAdd->r3Vector.size())
	{
		for(std::size_t i = 0; i < this->r3Vector.size(); i++) 
		{
			tempR2Tensor = r3Vector.at(i).addR2Tensor(&TensorToAdd->r3Vector.at(i));
            tempR3Tensor.addr2TensorToVector(&tempR2Tensor);
		}
	} else std::cout<<"Error: Dimension Mismatch to Add"<<std::endl;
    return tempR3Tensor;
    
}

void r3Tensor::addr2TensorToVector(const r2Tensor* TensorToAdd)
{//Private method to add a r2 tensor to the r3 tensor. This is a function used in the addition and multiplication
	this->r3Vector.push_back(*TensorToAdd);
}