#include "Books.h"

// 도서 정보 입력
Books::Books(std::string title, std::string author, std::string genre) :title(title), author(author), genre(genre) {}

// 도서 정보(제목, 저자, 장르) 반환
std::string Books::getTitle()
{
    return title;
}
std::string Books::getAuthor()
{
    return author;
}
std::string Books::getGenre()
{
    return genre;
}