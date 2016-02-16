#include <iostream>
#include "jumpit.h"
using namespace std;

const int PENALTY = 1000;	// Used to assign a very high cost

int jumpIt(const int board[], int startIndex, int endIndex)
{
    if(startIndex == endIndex)
    {
        return board[startIndex];
    }
    else if(startIndex+1 == endIndex)
    {
        return board[startIndex] + board[startIndex+1];
    }
    else
    {
        if(jumpIt(board,startIndex+1,endIndex) < jumpIt(board,startIndex+2,endIndex))
        {
            return board[startIndex] + jumpIt(board,startIndex+1,endIndex);
        }
        else
        {
            return board[startIndex] + jumpIt(board,startIndex+2,endIndex);
        }
    }

}
