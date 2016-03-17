#include "book.h"

bool operator <(const Book &book1, const Book &book2)
{
    return(book1.author<book2.author);
}
