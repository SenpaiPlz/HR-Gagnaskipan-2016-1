#include "Matrix.h"

//Initializes the Array as Mooshak does not accept non static initialize lists.

Matrix::Matrix()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            Arr[i][j] = 0;
        }
    }
}

Matrix::Matrix(const int& a, const int& b)
{
    Height = a;
    Width = b;
    for(int i = 0; i < Height; i++)
    {
        for(int j = 0; j < Width; j++)
        {
            Arr[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    //dtor
}

//Simple output operator overload

ostream& operator << (ostream& out, const Matrix& m)
{
    for(int i = 0; i < m.Height; i++)
    {
        for(int j = 0; j < m.Width; j++)
        {
            out << m.Arr[i][j] << "\t";
        }
        out << "\n";
    }

    return out;
}

//Simple input operator overload

istream& operator >> (istream& in, Matrix& m)
{
    for(int i = 0; i < m.Height; i++)
    {
        for(int j = 0; j < m.Width; j++)
        {
            in >> m.Arr[i][j];
        }
    }

    return in;
}

//+ operator overload for Matrix addition.

Matrix operator + (const Matrix& a, const Matrix& b)
{
    int H = b.Height;
    int W = b.Width;
    if( a.Height > b.Height)
    {
        H = a.Height;
    }
    if( a.Width > b.Width)
    {
        H = a.Width;
    }
    Matrix ret(H,W);

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            ret.Arr[i][j] = a.Arr[i][j] + b.Arr[i][j];
        }
    }

    return ret;
}

//* operator overload for Matrix multiplication (set of vector dot products).

Matrix operator * (const Matrix& a, const Matrix& b)
{
    //Atm assumes that the matrix multiplication has correct parameters.
    int H = b.Height;
    int W = b.Width;
    if( a.Height < b.Height)
    {
        H = a.Height;
    }
    if( a.Width < b.Width)
    {
        H = a.Width;
    }
    Matrix ret(H,W);

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            for(int k = 0; k < a.Width; k++)
            {
                ret.Arr[i][j] += a.Arr[i][k] * b.Arr[k][j];
            }
        }
    }

    return ret;
}

//Creates a Array that is the source array transposed.

Matrix Matrix::transpose()
{
    Matrix temp(Width,Height);

    for(int i = 0; i < Width; i++)
    {
        for(int j = 0; j < Height; j++)
        {
            temp.Arr[i][j] = Arr[j][i];
        }
    }
    return temp;
}
