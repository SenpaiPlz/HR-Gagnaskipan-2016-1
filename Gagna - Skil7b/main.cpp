// ****************************************************************
//
// This program implements an in-memory database of books using
// a vector and sorts them using the generic sort function from
// the algorithm library.
// ****************************************************************

#include <vector>
#include <algorithm>
#include "book.h"

using namespace std;

// Function prototypes
void AddNewBook(vector<Book> &bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();


int main()
{
    vector<Book> db;
    int i;
    bool quit = false;
    do
    {
        PrintMenu();
        cin >> i;
        switch(i)
        {
            case 1 : AddNewBook(db); break;
            case 2 : PrintBooks(db); break;
            case 3 : quit = true; break;
        }
    }while(quit == false);
}

void PrintMenu()
{
    cout << "1.\tAdd New Book\n";
    cout << "2.\tPrint listing sorted by author\n";
    cout << "3.\tQuit\n";
}

void PrintBooks(vector<Book> &bookdata)
{
    sort(bookdata.begin(),bookdata.end());

    cout << "\nThe books entered so far, sorted alphabetically by author are:\n";
    for(vector<Book>::iterator i = bookdata.begin(); i != bookdata.end(); i++)
    {
        cout << "\t" << i->getAuthor() << " " << i->getTitle() << " " << i->getDate() << endl;
    }
    cout << endl;
}


void AddNewBook(vector<Book> &bookdata)
{
    string tmptitle;
    string tmpauthor;
    string tmpdate;
    cin.ignore(1);
    cout << "\nEnter Title:\n";
    getline(cin,tmptitle);
    cout << "\nEnter author:\n";
    getline(cin,tmpauthor);
    cout << "\nEnter date:\n";
    getline(cin,tmpdate);
    cout << endl;

    Book tmpbook(tmpauthor,tmptitle,tmpdate);

    bookdata.push_back(tmpbook);
}
