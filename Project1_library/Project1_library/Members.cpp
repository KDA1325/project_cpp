#include "Members.h"
#include <iostream>
#include <string>
#include <vector>
#include "Books.h"

// 회원 정보 입력
Members::Members(std::string name, int memberId) :name(name), memberId(memberId) {}

// 회원 정보(이름, 아이디) 반환
std::string Members::getName()
{
    return name;
}
int Members::getMemberId() {
    return memberId;
}

// 도서 대출 기능
void Members::borrowBook(Books* book) {
    borrowedBooks.push_back(book);
    std::cout << std::endl << book->getTitle() << " 대출되었습니다." << std::endl << std::endl;
}

// 도서 반납 기능
void Members::returnBook(Books* book) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == book) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            std::cout << std::endl << book->getTitle() << " 반납되었습니다." << std::endl << std::endl;
            return;
        }
    }

    std::cout << "해당 도서는 대출 중이 아닙니다." << std::endl;
}

// 대출 현황 출력
void Members::displayBorrowedBooks() {
    std::cout << "=======================================================" << std::endl;
    std::cout << "<대출 현황>" << std::endl;
    if (borrowedBooks.empty()) {
        std::cout << "현재 대출 중인 도서가 없습니다." << std::endl;
        std::cout << "=======================================================" << std::endl;
    }
    else {
        for (int i = 0; i < borrowedBooks.size(); i++)
        {
            Books* book = borrowedBooks[i];
            std::cout << i + 1 << ". " << book->getTitle() << " (저자: " << book->getAuthor() << ", 장르: " << book->getGenre() << ")" << std::endl;
        }
        std::cout << "=======================================================" << std::endl;
    }
}

// 대출 도서 번호 반환
int Members::getNumOfBorrowedBooks() {
    return borrowedBooks.size();
}

// 대출 도서 정보 반환
Books* Members::getBorrowedBook(int index) {
    if (index >= 0 && index < borrowedBooks.size()) {
        return borrowedBooks[index];
    }
    return nullptr;
}