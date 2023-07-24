#include "Library.h"
#include "Books.h"
#include "Members.h"

int main() {
    Library library;

    // 도서/회원 정보 저장
    Books book1("다빈치코드", "댄 브라운", "추리");
    Books book2("데미안", "헤르만 헤세", "픽션");
    Books book3("가시고기", "조창인", "드라마");
    Books book4("셜록 홈즈의 모험", "아서 코난 도일", "추리");

    Members member1("김다애", 1234);
    Members member2("홍길동", 5678);

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);
    library.addBook(&book4);

    library.addMember(&member1);
    library.addMember(&member2);

    std::cout << "=======================================================" << std::endl;
    std::cout << "도서관 관리 시스템" << std::endl;
    std::cout << "=======================================================" << std::endl << std::endl;

    // 회원 목록 출력
    library.displayMemberList();

    std::cout << "> 아이디를 입력해 주세요." << std::endl << std::endl;
    std::cout << "입력> ";

    int memberId;
    std::cin >> memberId;

    library.checkIdFormat(memberId);

    return 0;
}
