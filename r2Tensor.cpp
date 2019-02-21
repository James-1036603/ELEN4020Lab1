#include "r2Tensor.h"

r2Tensor::r2Tensor(std::size_t x, std::size_t y)
{//Creates an empty rank 2 tensor
	r2Tensor::initVector(x,y);	
}

r2Tensor::r2TensorPopulated(std::size_t x, std::size_t y)
{//Creates a populated rank 2 tensor
	r2Tensor::initVector(x,y);
	r2Tensor::populateVetor();
}

void r2Tensor::changeAtPosition(std::size_t x, std::size_t y, int val)
{//Change value at position
	r2Tensor::r2Vector.at(x).at(y) = val;
}

void r2Tensor::initVector(std::size_t x, std::size_t y)
{//Initialise the 2D vector to a size x and y
	for(std::size_t i = 0; i < x; i++)
	{
		std::vector<int> tempY(y);
		r2Tensor::r2Vector.push_back(tempY);
	}
}

void r2Tensor::populateVetor()
{//Populate the 2D Tensor with random values
	for(std::size_t i = 0; i < r2Tensor::r2Vector.size(); i++)
	{
		for(std::size_t j = 0; j < r2Tensor::r2Vector.at(i).size(); j++)
		{
			r2Tensor::r2Vector.at(i).at(j) = std::rand() % 10;
		}
	}
}


r2Tensor r2Tensor::addR2Tensor(const r2Tensor* TensorToAdd)
{//Adds another tensor to the current one. Will return a new unique tensor
	//first check nxm vs nxm for addition, then add.
	
	
}