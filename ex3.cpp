#include <iostream>
#include <cassert>
using namespace std;

class Matrix{
    private:
    int data[2][2];

    public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix operator+(const Matrix &m)
    {
        Matrix result;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &m){
        Matrix result;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                result.data[i][j] = 0;

                for(int k = 0; k < 2; k++){
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

    int* operator[](int index){
        return data[index];
    }

    friend ostream& operator<< (ostream &out, const Matrix &m){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                out << m.data[i][j] << " ";
                
            }
            out << endl;
        }
        return out;
    }
};

int main(){
    Matrix A(2, 4, 4, 8);
    Matrix B(5, 7, 4, 5);
    Matrix sum = A + B;
    Matrix product = A*B;

    //Unit Tests
    assert(sum[0][0] == 7);
    assert(sum[1][1] == 13);
    assert(product[0][0] == 26);
    assert(product[0][1] == 34);
    assert(product[1][0] == 52);
    assert(product[1][1] == 68);

    cout << "Matrix A: " << endl;
    cout << A;
    cout << "Matrix B: " << endl;
    cout << B;

    cout << "Addition of matrices: " << endl;
    cout << sum;
    cout << "Multiplication of matrices: " << endl;
    cout << product;
    cout << "All unit tests passed successfully." << endl;
    return 0;
}