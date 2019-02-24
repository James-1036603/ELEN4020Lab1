#include "r2Tensor.h"

r2Tensor::r2Tensor(std::size_t x, std::size_t y, const bool populated)
{//Creates an empty rank 2 tensor
	r2Tensor::initVector(x,y);	
	if(populated) populateVetor();	
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
			r2Tensor::r2Vector.at(i).at(j) = std::rand() % 20 +1;
		}
	}
}


r2Tensor r2Tensor::rank2TensorAdd(const r2Tensor* TensorToAdd)
{//Adds another tensor to the current one. Will return a new unique tensor
	//first check nxm vs nxm for addition, then add.
	r2Tensor tempTensor(this->r2Vector.size(), this->r2Vector.at(0).size(),0);
	
	if((this->r2Vector.size() == TensorToAdd->r2Vector.size()) && ((this->r2Vector.at(0).size() == TensorToAdd->r2Vector.at(0).size())))
	{
		for(std::size_t i = 0; i < this->r2Vector.size(); i++)
		{
			for(std::size_t j = 0; j < this->r2Vector.at(i).size(); j++)
			{
				tempTensor.r2Vector.at(i).at(j) = this->r2Vector.at(i).at(j) + TensorToAdd->r2Vector.at(i).at(j);
			}			
		}
	} else r2ErrorLogger.logError("Error: Dimension mismatch for adding 2D Matrix.");
	return tempTensor;
}


r2Tensor r2Tensor::rank2TensorMult(const r2Tensor* TensorToMult)
{//Multiply two r2Tensors together.
//Check for nxm vs mxn that m = m. Will return a nxn tensor
	r2Tensor tempTensor(this->r2Vector.at(0).size(), this->r2Vector.size(),0);
	
	if(this->r2Vector.size() == TensorToMult->r2Vector.at(0).size())
	{//mult cols by rows and add. Think this assumes nxn and not nxm
		for(std::size_t i = 0; i < this->r2Vector.size(); i++)
		{
			for(std::size_t j = 0; j < this->r2Vector.size(); j++)
			{
				auto tempSol = 0;
				for(std::size_t k = 0; k < TensorToMult->r2Vector.size(); k++)
				{
					tempSol += this->r2Vector.at(i).at(k)*TensorToMult->r2Vector.at(k).at(j);
				}
				tempTensor.r2Vector.at(i).at(j) = tempSol;
			}
		}
	} else r2ErrorLogger.logError("Error: Dimension mismatch for multiplying 2D Matrix");
	
	return tempTensor;
}

void r2Tensor::printTensor()
{
	for(std::size_t i = 0; i < r2Tensor::r2Vector.size(); i++)
	{
		for(std::size_t j = 0; j < r2Tensor::r2Vector.at(i).size(); j++)
		{
			std::cout<<r2Vector.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
}

