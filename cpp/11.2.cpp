#include <iostream>
#include <string>
using namespace std;

class Matrix 
{
	private:
		int mat[2][2];
		
	public:
		Matrix(int a11 = 0, int a12 = 0, int a21 = 0, int a22 = 0) 
		{
			mat[0][0] = a11;
			mat[0][1] = a12;
			mat[1][0] = a21;
			mat[1][1] = a22;
		}
		
		Matrix operator-(const Matrix& other) const 
		{
			Matrix result;
			result.mat[0][0] = mat[0][0] - other.mat[0][0];
			result.mat[0][1] = mat[0][1] - other.mat[0][1];
			result.mat[1][0] = mat[1][0] - other.mat[1][0];
			result.mat[1][1] = mat[1][1] - other.mat[1][1];
			return result;
		}
		void display() const {
			cout << mat[0][0] << " " << mat[0][1] << endl;
			cout << mat[1][0] << " " << mat[1][1] << endl;
		}
};

int main() {
	Matrix matrix1(1, 5, 7, 6);
	Matrix matrix2(3, 4, 1, 2);
	
	cout << "Matrix 1:" <<endl;
	matrix1.display();
	cout << endl;
	
	cout << "Matrix 2:" <<endl;
	matrix2.display();
	cout << endl;
	
	Matrix result = matrix1 - matrix2;
	cout << "Resulting Matrix after subtraction:" <<endl;
	result.display();
	
	return 0;
}
