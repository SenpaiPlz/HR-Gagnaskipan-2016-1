#include "Matrix.h"

Matrix::Matrix(const int& a, const int& b)
{
    Height = a;
    Width = b;
}

Matrix::~Matrix()
{
    //dtor
}

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
