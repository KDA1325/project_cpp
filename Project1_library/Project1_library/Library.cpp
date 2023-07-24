#include "Library.h"

// ���� �߰�
void Library::addBook(Books* book)
{
    books.push_back(book);
}

// ȸ�� �߰�
void Library::addMember(Members* member)
{
    members.push_back(member);
}

// ���� ��� ���
void Library::displayBookList()
{
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "<���� ��ġ�� ���� ���>" << std::endl;
    for (int i = 0; i < books.size(); i++) {
        Books* book = books[i];
        std::cout << i + 1 << ". " << book->getTitle() << " (����: " << book->getAuthor() << ", �帣: " << book->getGenre() << ")" << std::endl;
    }
}

// ȸ�� ��� ���
void Library::displayMemberList()
{
    std::cout << "<ȸ�� ����Ʈ>" << std::endl;
    for (int i = 0; i < members.size(); i++)
    {
        Members* member = members[i];
        std::cout << i + 1 << ". " << member->getName() << "(ID: " << member->getMemberId() << ")" << std::endl;
    }
}

// ���̵� ���� üũ
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

        // ȸ�� ���̵� ��ġ �Ǵ�
        if (selectedMember != nullptr) {
            memberProcess(selectedMember);
        }
        else {
            std::cout << "�߸��� ���̵��Դϴ�." << std::endl;
        }
    }
    else {
        std::cout << "�߸��� ���̵� �����Դϴ�." << std::endl;
    }
}

void Library::memberProcess(Members* member)
{
    // ����/�ݳ� �ɼ� ����
MemberCheck:
    std::cout << "=======================================================" << std::endl;
    std::cout << "ȸ��: " << member->getName() << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "���� ����: 1" << std::endl;
    std::cout << "���� �ݳ�: 2" << std::endl;
    std::cout << "����: 0" << std::endl;
    std::cout << std::endl;

    int choice;
    int bookNum;

    while (true) {
        std::cout << "�Է�> ";
        std::cin >> choice;

        switch (choice)
        {
            // ���� ����
        case 1:
        Borrow:
            displayBookList();
            std::cout << std::endl;
            std::cout << "> �����Ͻ� å�� ��ȣ�� �Է��� �ּ���." << std::endl;
            std::cout << "> �ڷΰ���� 0�� �Է��� �ּ���." << std::endl;
            std::cout << "> ���� ��Ȳ Ȯ���� 900�� �Է��� �ּ���." << std::endl << std::endl;
            std::cout << "�Է�> ";

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
                std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << std::endl;
                goto Borrow;
                break;
            }

            // ���� �ݳ�
        case 2:
        Return:
            member->displayBorrowedBooks();
            std::cout << std::endl;
            std::cout << "> �ݳ��Ͻ� å�� ��ȣ�� �Է��� �ּ���." << std::endl;
            std::cout << "> �ڷΰ���� 0�� �Է��� �ּ���." << std::endl;
            std::cout << "> ���� ��Ȳ Ȯ���� 900�� �Է��� �ּ���." << std::endl;
            std::cout << "�Է�> ";

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
                    std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << std::endl;
                    goto Return;
                    break;
                }
            }

            // ����
        case 0:
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break;

            // �� ��
        default:
            std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ֻ���." << std::endl;
            goto MemberCheck;
            break;
        }
        break;
    }
}