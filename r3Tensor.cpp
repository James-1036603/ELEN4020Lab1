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
	
	if(this->r3Vector.size() == TensorToAdd->r3Vector.size())
	{
		for(std::size_t i = 0; i < this->r3Vector.size(); i++) 
		{
			
		}
	} else std::cout<<"Error: Dimension Mismatch to Add"<<std::endl;
}

void r3Tensor::addr2TensorToVector(const r2Tensor* TensorToAdd)
{//Private method to add a r2 tensor to the r3 tensor. This is a function used in the addition and multiplication
	this->r3Vector.push_back(*TensorToAdd);
}