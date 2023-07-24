#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <string>

class Books
{
private:
    std::string title;
    std::string author;
    std::string genre;

public:
    Books(std::string title, std::string author, std::string genre);
    std::string getTitle();
    std::string getAuthor();
    std::string getGenre();
};

#endif // !BOOKS_H