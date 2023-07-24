#ifndef MEMBERS_H
#define MEMBERS_H
#include <iostream>
#include <string>
#include <vector>
#include "Books.h"

class Members
{
private:
    std::string name;
    int memberId;
    std::vector<Books*> borrowedBooks;

public:
    Members(std::string name, int memberId);
    std::string getName();
    int getMemberId();
    void borrowBook(Books* book);
    void returnBook(Books* book);
    void displayBorrowedBooks();
    int getNumOfBorrowedBooks();
    Books* getBorrowedBook(int index);
};
#endif // !MEMBERS_H