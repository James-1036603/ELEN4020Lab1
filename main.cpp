#include <cstdlib>
#include <iostream>
#include <time.h>
#include "r2Tensor.h"
#include "r3Tensor.h"

using namespace std;


int main()
{	
	srand(time(NULL));
	char choice = ' ';
	
	r2Tensor first2DMatrix(10,10,1), second2DMatrix(10,10,1), result2DMatrix;
	r3Tensor first3DMatrix(10,10,10,1), second3DMatrix(10,10,10,1), result3DMatrix;
	
	while(choice != 'x')
	{
		cout<<"Enter your choice: \n"<<
		"1. Create two N = 10 2D matrices with random values and print them.\n"<<
		"2. Create two N = 20 2D matrices with random values and print them.\n"<<
		"3. Perform addition on the current two 2D matrices and print the result.\n"<<
		"4. Perform multiplication on the current two 2D matrices and print the result.\n"<<
		"5. Print the current two 2D matrices.\n"<<
		"6. Create two N = 10 3D matrices with random values and print them.\n"<<
		"7. Create two N = 20 3D matrices with random values and print them.\n"<<
		"8. Perform addition on the current two 3D matrices and print the result.\n"<<
		"9. Perform multiplication on the current two 3D matrices and print the result.\n"<<
		"10. Print the current two 3D matrices.\n"<<
		"x to exit."<<endl;
		cin>>choice;
		
		if(choice == '1')
		{
			cout<<"Creating two random N=10 2D Matrices..."<<endl;
			first2DMatrix = r2Tensor(10,10,1);
			second2DMatrix = r2Tensor(10,10,1);
			cout<<"First Matrix: "<<endl;
			first2DMatrix.printTensor();
			cout<<"Second Matrix: "<<endl;
			second2DMatrix.printTensor();
		} else if(choice == '2')
		{
			cout<<"Creating two random N=20 2D Matrices..."<<endl;
			first2DMatrix = r2Tensor(20,20,1);
			second2DMatrix = r2Tensor(20,20,1);
			cout<<"First Matrix: "<<endl;
			first2DMatrix.printTensor();
			cout<<"Second Matrix: "<<endl;
			second2DMatrix.printTensor();
		} else if(choice == '3')
		{
			cout<<"Adding Matrix A and B together..."<<endl;
			result2DMatrix = first2DMatrix.rank2TensorAdd(&second2DMatrix);
			result2DMatrix.printTensor();
		} else if(choice == '4')
		{
			cout<<"Multiplying Matrix A and B together..."<<endl;
			result2DMatrix = first2DMatrix.rank2TensorMult(&second2DMatrix);
			result2DMatrix.printTensor();
		} else if(choice == '5')
		{
			first2DMatrix.printTensor();
			second2DMatrix.printTensor();
		} else if(choice == '6')
		{
			cout<<"Creating two random N=10 3D Matrices..."<<endl;
			first3DMatrix = r3Tensor(10,10,10,1);
			second3DMatrix = r3Tensor(10,10,10,1);
			cout<<"First Matrix: "<<endl;
			first3DMatrix.printTensor();
			cout<<"Second Matrix: "<<endl;
			second3DMatrix.printTensor();
		} else if(choice == '7')
		{
			cout<<"Creating two random N=20 3D Matrices..."<<endl;
			first3DMatrix = r3Tensor(20,20,20,1);
			second3DMatrix = r3Tensor(20,20,20,1);
			cout<<"First Matrix: "<<endl;
			first3DMatrix.printTensor();
			cout<<"Second Matrix: "<<endl;
			second3DMatrix.printTensor();
		} else if(choice == '8')
		{
			cout<<"Adding Matrix C and D together..."<<endl;
			result3DMatrix = first3DMatrix.rank3TensorAdd(&second3DMatrix);
			result3DMatrix.printTensor();
		} else if(choice == '9')
		{
			cout<<"Multiplying Matrix C and D together..."<<endl;
			result3DMatrix = first3DMatrix.rank3TensorMult(&second3DMatrix);
			result3DMatrix.printTensor();
		} else
		{
			cout<<"Invalid input."<<endl;
		}
			
	}
	
	
	return 0;
}
