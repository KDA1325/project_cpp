#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  
#include "Books.h"
#include "Members.h"

class Library
{
private:
    std::vector<Books*> books;
    std::vector<Members*> members;

public:
    void addBook(Books* book);
    void addMember(Members* member);

    std::vector<Members*> getMembers() {
        return members;
    }
    void checkIdFormat(int memberId);
    void displayBookList();
    void displayMemberList();
    void memberProcess(Members* member);

};
#endif // !LIBRARY_H