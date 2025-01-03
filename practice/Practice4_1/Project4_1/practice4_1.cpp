#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(string title) {
        //사실 for문으로 돌아도 될것같긴한데..
        for (std::vector<Book>::iterator it = books.begin();
            it != books.end();
            it++
            )
        {
            if (it->title == title) {
                cout << "title exist" << endl;
            }
            
        }
    
    }
    void searchByAuthor(string author) {
        for (std::vector<Book>::iterator it = books.begin();
            it != books.end();
            it++
            )
        {
            if (it->author == author) {
                cout << " author exist" << endl;
            }

        }
    }
};

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 검색" << endl; // 프로그램 종료
        cout << "4. 작가 검색" << endl; // 프로그램 종료
        cout << "5. 종료" << endl; // 프로그램 종료

        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
           // 버퍼 생각
            //책검색
            string title; 
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
            int choice2;  //getLine은 스트링만 받을 수 있구나?
            cout << "계속 검색하시겠습니까? : ";
            cout << "yes =1 , no = 0 "<<"\n";
            cin >> choice2;
            if (choice2 == 1) {
                while (1) {
                    string title;
                    cout << "검색할 책 제목: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "title : " << title << "\n";
                    manager.searchByTitle(title);
                    int choice2;
                    cout << "계속 검색하시겠습니까? : "<<"\n";
                    cout << "yes =1 , no = 0 " ;

                    cin >> choice2;
                    if (choice2 == 0) break;
                }
            }
        }
        else if (choice == 4) {
            //작가 검색
            string author;
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
            int choice2;  //getLine은 스트링만 받을 수 있구나?
            cout << "계속 검색하시겠습니까? : ";
            cout << "yes =1 , no = 0 "; 
            cin >>  choice2;
            // 이거 안써도 될것같은데? 와일돌때 시작하면서 다 공백 먹고들어가니깐cin.ignore();
            if (choice2 == 1) {
                while (1) {
                    string author;
                    cout << "검색할 책 제목: ";
                    cin.ignore();
                    getline(cin, author);
                    cout << "author : " << author << "\n";
                    manager.searchByAuthor(author);
                    int choice2;
                    cout << "계속 검색하시겠습니까? : ";
                    cout << "yes =1 , no = 0 ";
                    
                    cin >> choice2;
                    if (choice2 == 0) break;
                }
            }
            //계속 검색을 원하면 여기에 있고
            // 그게 아니라면 밖으로 
        }
        else if (choice == 5) {
            // 5번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 프로그램이 종료됩니다." << endl;
            break;
        }
    }

    return 0; // 프로그램 정상 종료
}