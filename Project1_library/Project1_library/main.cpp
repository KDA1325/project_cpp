#include "Library.h"
#include "Books.h"
#include "Members.h"

int main() {
    Library library;

    // ����/ȸ�� ���� ����
    Books book1("�ٺ�ġ�ڵ�", "�� ����", "�߸�");
    Books book2("���̾�", "�츣�� �켼", "�ȼ�");
    Books book3("���ð��", "��â��", "���");
    Books book4("�ȷ� Ȩ���� ����", "�Ƽ� �ڳ� ����", "�߸�");

    Members member1("��پ�", 1234);
    Members member2("ȫ�浿", 5678);

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);
    library.addBook(&book4);

    library.addMember(&member1);
    library.addMember(&member2);

    std::cout << "=======================================================" << std::endl;
    std::cout << "������ ���� �ý���" << std::endl;
    std::cout << "=======================================================" << std::endl << std::endl;

    // ȸ�� ��� ���
    library.displayMemberList();

    std::cout << "> ���̵� �Է��� �ּ���." << std::endl << std::endl;
    std::cout << "�Է�> ";

    int memberId;
    std::cin >> memberId;

    library.checkIdFormat(memberId);

    return 0;
}
