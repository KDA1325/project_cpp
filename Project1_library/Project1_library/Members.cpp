#include "Members.h"
#include <iostream>
#include <string>
#include <vector>
#include "Books.h"

// ȸ�� ���� �Է�
Members::Members(std::string name, int memberId) :name(name), memberId(memberId) {}

// ȸ�� ����(�̸�, ���̵�) ��ȯ
std::string Members::getName()
{
    return name;
}
int Members::getMemberId() {
    return memberId;
}

// ���� ���� ���
void Members::borrowBook(Books* book) {
    borrowedBooks.push_back(book);
    std::cout << std::endl << book->getTitle() << " ����Ǿ����ϴ�." << std::endl << std::endl;
}

// ���� �ݳ� ���
void Members::returnBook(Books* book) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == book) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            std::cout << std::endl << book->getTitle() << " �ݳ��Ǿ����ϴ�." << std::endl << std::endl;
            return;
        }
    }

    std::cout << "�ش� ������ ���� ���� �ƴմϴ�." << std::endl;
}

// ���� ��Ȳ ���
void Members::displayBorrowedBooks() {
    std::cout << "=======================================================" << std::endl;
    std::cout << "<���� ��Ȳ>" << std::endl;
    if (borrowedBooks.empty()) {
        std::cout << "���� ���� ���� ������ �����ϴ�." << std::endl;
        std::cout << "=======================================================" << std::endl;
    }
    else {
        for (int i = 0; i < borrowedBooks.size(); i++)
        {
            Books* book = borrowedBooks[i];
            std::cout << i + 1 << ". " << book->getTitle() << " (����: " << book->getAuthor() << ", �帣: " << book->getGenre() << ")" << std::endl;
        }
        std::cout << "=======================================================" << std::endl;
    }
}

// ���� ���� ��ȣ ��ȯ
int Members::getNumOfBorrowedBooks() {
    return borrowedBooks.size();
}

// ���� ���� ���� ��ȯ
Books* Members::getBorrowedBook(int index) {
    if (index >= 0 && index < borrowedBooks.size()) {
        return borrowedBooks[index];
    }
    return nullptr;
}