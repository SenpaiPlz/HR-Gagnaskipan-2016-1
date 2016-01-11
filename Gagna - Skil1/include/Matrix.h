#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class Matrix
{
    public:
        Matrix(const int& a, const int& b);
        friend ostream& operator << (ostream& out, const Matrix& m);
        friend istream& operator >> (istream& in, Matrix& m);
        friend Matrix operator + (const Matrix& a, const Matrix& b);
        friend Matrix operator * (const Matrix& a, const Matrix& b);
        Matrix transpose();
        virtual ~Matrix();
    protected:
    private:
        static const int MAX = 5;
        int Arr[MAX][MAX] = {};
        int Height;
        int Width;
};

#endif // MATRIX_H
