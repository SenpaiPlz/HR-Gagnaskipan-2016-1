#include "palindrome.h"

bool palindrome(const char a[], int first, int last)
{
    if(first == last || first > last)
    {
        //stop condition
        return true;
    }
    else
    {
        //got correct for an incorrect solution before.
        if(a[first] == a[last])
        {
			//checks all the position not all from 1 to n-1 like last time.
            return true&&palindrome(a,first+1,last-1);
        }
        else
        {
            return false;
        }
    }
}
