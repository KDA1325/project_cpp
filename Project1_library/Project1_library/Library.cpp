#include "Library.h"

// 도서 추가
void Library::addBook(Books* book)
{
    books.push_back(book);
}

// 회원 추가
void Library::addMember(Members* member)
{
    members.push_back(member);
}

// 도서 목록 출력
void Library::displayBookList()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "<현재 비치된 도서 목록>" << std::endl;
    for (int i = 0; i < books.size(); i++) {
        Books* book = books[i];
        std::cout << i + 1 << ". " << book->getTitle() << " (저자: " << book->getAuthor() << ", 장르: " << book->getGenre() << ")" << std::endl;
    }
}

// 회원 목록 출력
void Library::displayMemberList()
{
    std::cout << "<회원 리스트>" << std::endl;
    for (int i = 0; i < members.size(); i++)
    {
        Members* member = members[i];
        std::cout << i + 1 << ". " << member->getName() << "(ID: " << member->getMemberId() << ")" << std::endl;
    }
}

// 아이디 형식 체크
void Library::checkIdFormat(int memberId)
{
    if (memberId >= 1000 && memberId <= 9999) {
        Members* selectedMember = nullptr;
        for (Members* member : getMembers()) {
            if (member->getMemberId() == memberId) {
                selectedMember = member;
                break;
            }
        }

        // 회원 아이디 일치 판단
        if (selectedMember != nullptr) {
            memberProcess(selectedMember);
        }
        else {
            std::cout << "잘못된 아이디입니다." << std::endl;
        }
    }
    else {
        std::cout << "잘못된 아이디 형식입니다." << std::endl;
    }
}

void Library::memberProcess(Members* member)
{
    // 대출/반납 옵션 선택
MemberCheck:
    std::cout << "=======================================================" << std::endl;
    std::cout << "회원: " << member->getName() << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "도서 대출: 1" << std::endl;
    std::cout << "도서 반납: 2" << std::endl;
    std::cout << "종료: 0" << std::endl;
    std::cout << std::endl;

    int choice;
    int bookNum;

    while (true) {
        std::cout << "입력> ";
        std::cin >> choice;

        switch (choice)
        {
            // 도서 대출
        case 1:
        Borrow:
            displayBookList();
            std::cout << std::endl;
            std::cout << "> 대출하실 책의 번호를 입력해 주세요." << std::endl;
            std::cout << "> 뒤로가기는 0을 입력해 주세요." << std::endl;
            std::cout << "> 대출 현황 확인은 900을 입력해 주세요." << std::endl << std::endl;
            std::cout << "입력> ";

            int borrowChoice;
            std::cin >> borrowChoice;

            if (borrowChoice == 0) {
                goto MemberCheck;
                break;
            }
            else if (borrowChoice == 900) {
                member->displayBorrowedBooks();
                goto Borrow;
                break;
            }
            else if (borrowChoice >= 1 && borrowChoice <= books.size()) {
                Books* selectedBook = books[borrowChoice - 1];
                member->borrowBook(selectedBook);
                goto Borrow;
                break;
            }
            else {
                std::cout << "잘못된 입력입니다. 다시 입력해 주세요." << std::endl;
                goto Borrow;
                break;
            }

            // 도서 반납
        case 2:
        Return:
            member->displayBorrowedBooks();
            std::cout << std::endl;
            std::cout << "> 반납하실 책의 번호를 입력해 주세요." << std::endl;
            std::cout << "> 뒤로가기는 0을 입력해 주세요." << std::endl;
            std::cout << "> 대출 현황 확인은 900을 입력해 주세요." << std::endl;
            std::cout << "입력> ";

            int bookChoice;
            std::cin >> bookChoice;

            if (bookChoice == 0) {
                goto MemberCheck;
                break;
            }
            else if (bookChoice == 900) {
                member->displayBorrowedBooks();
                break;
            }
            else {
                if (bookChoice >= 1 && bookChoice <= member->getNumOfBorrowedBooks()) {
                    Books* selectedBook = member->getBorrowedBook(bookChoice - 1);
                    member->returnBook(selectedBook);
                    goto Return;
                    break;
                }
                else {
                    std::cout << "잘못된 입력입니다. 다시 입력해 주세요." << std::endl;
                    goto Return;
                    break;
                }
            }

            // 종료
        case 0:
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;

            // 그 외
        default:
            std::cout << "잘못된 입력입니다. 다시 입력해 주새요." << std::endl;
            goto MemberCheck;
            break;
        }
        break;
    }
}