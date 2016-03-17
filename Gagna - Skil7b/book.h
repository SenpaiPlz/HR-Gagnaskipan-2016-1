#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
 public:
	Book() {}
	Book(string anAuthor, string aTitle, string aDate) : author(anAuthor), title(aTitle), date(aDate) {}
	string getAuthor() const {return author;}
	string getTitle() const {return title;}
	string getDate() const {return date;}
	friend bool operator <(const Book &book1, const Book &book2);
 private:
	string author;
	string title;
	string date;
};
#endif // BOOK_H
