#include "Books.h"

// ���� ���� �Է�
Books::Books(std::string title, std::string author, std::string genre) :title(title), author(author), genre(genre) {}

// ���� ����(����, ����, �帣) ��ȯ
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