


/////////////////////////////////////////
/**4-2*/
//////////////////////////////////////////

/**
도전 기능
1. 특정 책의 대여 여부를 알아야한다
2. 책의 이름으로 대여 여부를 검색하고, 대여가 아닌 경우 대여할 수 있어야한다
3. 책의 작가로 대여 여부
4. 책을 반납할 수 있어야한다.
5. 책의 재고는 3권으로 통일
*/

/** 과제4 PIL
* 1. 너무 클래스 안에 한정시켜서 생각을 했다 =>메인에서 값을 받아와서 해도 되는데 메인에서 받는 방법이 떠오르지 않았습니다.
* 2. 클래스 다이어그램이 무엇을 요구하는지 느낌이 왔습니다. 북매니저와 북 그리고 재고관리자는 서로를 몰라야합니다.
* 3. 과제가 요구하는 바를 알지만, 만일 재고관리자에서 북매니저를 호출하는 경우가 생긴다면 그때는 결합도가 올라갑니다.
* 4. 공부가 목적이니 만큼 재고관리자가 북매니저를 호출하는 경우를 생각하여 결합도를 낮추는 방법을 생각해보았습니다.
*    따라서 재고관리자가 작가의 이름을 받을 경우, 북매니저를 호출하는 방식을 같이 사용하였습니다.
*    인터페이스가 없을 시 메인함수에서 재고관리를 다루는 로직
*    사용자 작가이름 입력 -> manager 북 반환 -> 책의 제목 추출 -> 재고관리 호출
* 5. 그중 인터페이스를 하나 만들면 결합도가 낮아진다는 것을 알게되었습니다.
* 6. 따라서 이번 과제는 과제의 요구사항도 구현함과 동시에 인터페이스를 구현하여 결합도를 낮추는 방향으로 진행려 합니다.
* 7. nullptr을 예외처리하는데 있어 , try catch를 연습해봤습니다.
* 8. get,Find
* 9. TIL에 정리 해야할 것 : Const, 스마트 포인터 ,auto , for문 업그레이드 , & , try catch,
*                         main함수 내의 result로 받는 부분  ,cin
* get = 처음에는 확장성을 위해 열어놓는건가?라는 생각이 들었다.
		 결국에는 사전 점검 문자열 파싱 등 사전의 에러를 점검하는곳
		 따라서 find에서는 결국 내가 책들을 건들기 때문에 private 설정

* find = find에 들어오는 값은 에러가 없는 문자열이며 이곳에서 nullptr을 반환시 찾는 책이 없다
*
		main함수에서 3번과 4번을 선택할 때 )
		Book *m1  = getBookByTitle (); 을 진행한 후
		if (m1 == nullptr)
		{
			cout << "올바르지 않은 입력입니다_main !" << endl;

		}
		해당 함수를 사용하지 않아도 getBookByTitle안에서
		예외처리를 한다
		그렇기 때문에 메인함수안에서  m1을 사용하지 않는다면
		null만 리턴되고 null을 참조하는 일은 없다
		그러면 과연 이게 좋은 코드인가?
		메인함수에서 사용하는 사람이 처리를 해줘야하는 문제같다
		해당 getBookByTitle함수의 경우에는
		북 매니저와 재고관리가 main 다른 함수로 처리되기 때문에
		서로 알 필요가 없어서
		nullptr을 처리해줄 필요가 없다
		이런의미에서도 서로를 알 수 없게 하는게 좋은건가?

		하지만 적어도 case4에서는 사용해서는 안된다 .

		이유 :  result로 받아와서 밑의 로직에서 result->를 쓰기 때문이다
			   다시말해 result가 널 참조를 해서는 안된다.

*/


/**
*
* 2. 왜 cin에 choice2를 받는데 문자가 들어가면 빙글빙글 무한루프  도는지
TODO : 반납 대여 로직 작성 1시30분까지 끝내기

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Book {
public:
	string title;
	string author;

	Book(const string& title, const string& author)
		: title(title), author(author) {
	}
};


class IBookManager {
public:
	virtual Book* getBookByTitle(const string& title) = 0;
	virtual void addBook(const string& title, const string& author) = 0;
	virtual void displayAllBooks() const = 0;
	virtual Book* getBookByAuthor(const string& author) = 0;
	virtual ~IBookManager() = default;
	virtual const vector<Book>& getAllBooks() const = 0;
};


class BookManager : public IBookManager {
private:
	vector<Book> books; // 책 목록 저장

	Book* findBookByTitle(const string& title) {



		for (vector<Book>::iterator it2 = books.begin();
			it2 != books.end();
			it2++
			)
		{

			if (it2->title == title) {
				cout << "title exist" << endl;
				//여기서 리턴을 뭘 해야하지?
				return  &(*it2);
			}

		}
		// get을 호출하기 이전에 예외사항처리
		cout << "해당 책이 없습니다" << endl;

		return nullptr;
	}

	Book* findBookByAuthor(const string& author) {

		for (std::vector<Book>::iterator it = books.begin();
			it != books.end();
			it++
			)
		{
			if (it->author == author) {
				cout << " author exist" << endl;

				return &(*it);
			}

		}
		//get을 호출하기 이전에 예외사항처리
		cout << "해당 책이 없습니다" << endl;
		//지금까지 넘어왔다는건 return을 안했다는 소리이고, 찾는 값이 없다는 소리
		return nullptr;

	}
public:
	// 책 추가 메서드
	void addBook(const string& title, const string& author) override {
		if (title.length() >= 20 || author.length() >= 20) {
			cout << "Input Length Error" << endl;
			return;
		}
		books.push_back(Book(title, author)); // push_back 사용
		cout << "책이 추가되었습니다: " << title << " by " << author << endl;
	}

	// 모든 책 출력 메서드
	void displayAllBooks() const override {
		if (books.empty()) {
			cout << "현재 등록된 책이 없습니다." << endl;
			return;
		}

		cout << "현재 도서 목록:" << endl;
		for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
			cout << "- " << books[i].title << " by " << books[i].author << endl;
		}
	}


	Book* getBookByTitle(const string& title)  override {
		//title 유효성 검증
		//편의상 길이가 20을 초과하면 return 
		try {
			if (title.length() >= 20) {
				throw invalid_argument("작가의 이름이 20자를 초과합니다: Early Exit");
			}
			Book* tmp = findBookByTitle(title);
			if (tmp == nullptr) {
				throw runtime_error("해당 작가의 책을 찾을 수 없습니다.");
			}

			return tmp;
		}
		catch (const exception& e) {
			cerr << "오류 : " << e.what() << endl;
			return nullptr;
		}
	}

	// 이거 dangling pointer같은데
	// 스마트포인터사용해야하나? 



	Book* getBookByAuthor(const string& author) override {


		try {
			// 유효성 검사: 작가 이름 길이가 20 이상이면 예외 처리
			if (author.length() >= 20) {
				throw invalid_argument("작가의 이름이 20자를 초과합니다: Early Exit");
			}

			// 책 검색
			Book* tmp = findBookByAuthor(author);

			// 검색 결과가 없으면 예외 발생
			if (tmp == nullptr) {
				throw runtime_error("해당 작가의 책을 찾을 수 없습니다.");
			}

			// 검색 성공
			return tmp;

		}
		catch (const exception& e) {
			// 예외 메시지 출력
			cerr << "오류: " << e.what() << endl;
			return nullptr; // 예외 발생 시 nullptr 반환
		}

	}


	/**없어도 된다 하지만 공부를 위해 남겨두자 , 벡터로 다 받기보다는
	main에서 add할때마다 initialize 해주면된다 */
	const vector<Book>& getAllBooks() const override {
		return books;
	}

};

class BorrowManager {
private:
	unordered_map<string, int> stock;
	//약결합을 위해 borrow일 때만 재고를 생성하게 해보자 

public:

	BorrowManager() {
	}

	size_t getStockSize() const {
		return stock.size();
	}


	void initializeStock(const string& title, int quantity = 3) {
		stock[title] = quantity;

	}
	void borrowBookBytitle(const string& title) {
		unordered_map<string, int>::iterator it = stock.find(title);
		if (it == stock.end()) {
			cout << " 해당 책이 존재하지 않습니다. 제대로 입력해주세요 " << endl;
		}

		else if (it != stock.end()) {
			if (it->second == 0) {
				cout << "대여 가능한 책이 없습니다. 다음에 다시 찾아오세요" << endl;
			}
			else {
				cout << "대여 완료 " << endl;
				it->second--;
				cout << "대여 후 책 " << title << "의 남은 수량 : " << it->second << endl;
			}

		}

	}

	void borrowBookByAuthor(const string& author, IBookManager* m1) {
		Book* b;
		b = m1->getBookByAuthor(author);
		if (b == nullptr)
		{
			cout << "올바르지 않은 입력입니다 !" << endl;

		}
		else {
			unordered_map<string, int>::iterator it = stock.find(b->title);
			if (it == stock.end()) {
				cout << " 해당 책이 존재하지 않습니다. 제대로 입력해주세요 " << endl;
			}

			else if (it != stock.end()) {
				if (it->second == 0) {
					cout << "대여 가능한 책이 없습니다. 다음에 다시 찾아오세요" << endl;
				}
				else {
					cout << "대여 완료 " << endl;
					it->second--;
					cout << "대여 후 작가 : " << b->author << "   의" << "책 " << b->title << "의 남은 수량 : " << it->second << endl;
				}

			}
		}

	}

	void returnBookTitle(const string& title) {
		unordered_map<string, int>::iterator it = stock.find(title);
		if (it == stock.end()) {
			cout << " 해당 책이 존재하지 않습니다. 제대로 입력해주세요 " << endl;
		}

		else if (it != stock.end()) {
			if (it->second == 3) {
				cout << "반납 가능한 책이 없습니다.어디 도서관에서 훔쳐온거죠?! " << endl;
			}
			else {
				cout << "반납 완료 " << endl;
				it->second++;
				cout << "반납 후 책 " << title << "의 남은 수량 : " << it->second << endl;
			}

		}
	}
	void returnBookAuthor(const string& author, IBookManager* m1) {
		Book* b;
		b = m1->getBookByAuthor(author);
		if (b == nullptr) cout << "올바르지 않은 입력입니다 !" << endl;
		else {
			unordered_map<string, int>::iterator it = stock.find(b->title);
			if (it == stock.end()) {
				cout << " 해당 책이 존재하지 않습니다. 제대로 입력해주세요 " << endl;
			}

			else if (it != stock.end()) {
				if (it->second == 3) {
					cout << "반납 가능한 책이 없습니다.어디 도서관에서 훔쳐온거죠?! " << endl;
				}
				else {
					cout << "반납 완료 " << endl;
					it->second++;
					cout << "반납 후 작가 : " << b->author << "   의" << "책 " << b->title << "의 남은 수량 : " << it->second << endl;
				}

			}
		}
	}
	void displayStock(int k) {

		int kCnt = 0;
		for (unordered_map<string, int> ::iterator it = stock.begin();
			it != stock.end();
			it++
			)
		{
			if (kCnt == k) { break; }
			cout << "책 이름 : " << it->first << " - " << "남은 수량 : " << it->second << endl;
			kCnt++;
		}

	}

};

void printBoundary() {
	cout << "////////////////////////////////////////////////" << endl;
}

int main() {
	IBookManager* m;
	BookManager manager;
	m = &manager;
	BorrowManager b;

	// 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
	// 프로그램 종료를 선택하기 전까지 계속 동작합니다.
	while (true) {
		cout << "\n도서관 관리 프로그램" << endl;
		cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
		cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
		cout << "3. 책 검색" << endl; // 프로그램 종료
		cout << "4. 작가 검색" << endl; // 프로그램 종료
		cout << "5. 책 대여 문의" << endl;
		cout << "6. 책 반납 문의" << endl;
		cout << "7. 책 대여 가능 목록" << endl;
		cout << "0. 종료" << endl; // 프로그램 종료

		cout << "선택: ";

		int choice; // 사용자의 메뉴 선택을 저장
		cin >> choice;
		if (cin.fail() || (choice != 0 && choice != 1
			&& choice != 2 && choice != 3 && choice != 4
			&& choice != 5 && choice != 6 && choice != 7
			)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "잘못된 입력입니다. 올바른 수를 입력하세요 !" << endl;
			continue;
		}


		if (choice == 1) {
			printBoundary();
			cout << "책 추가하시려구요?? 어서오세요 사장님 빵끗 :)" << endl;
			// 1번 선택: 책 추가
			// 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
			string title, author;
			cout << "책 제목: ";
			cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
			getline(cin, title); // 제목 입력 (공백 포함)
			cout << "책 저자: ";
			getline(cin, author); // 저자명 입력 (공백 포함)
			m->addBook(title, author); // 입력받은 책 정보를 추가
			b.initializeStock(title);
		}
		else if (choice == 2) {
			printBoundary();
			cout << "책 목록 검색입니다 " << endl;
			// 2번 선택: 모든 책 출력
			// 현재 BookManager에 저장된 책 목록을 출력합니다.
			m->displayAllBooks();
		}
		else if (choice == 3) {
			printBoundary();
			cout << "제목 검색 입니다" << endl;
			// 버퍼 생각
			 //책검색
			string title;
			cout << "검색할 책 제목: ";
			cin.ignore();
			getline(cin, title);
			m->getBookByTitle(title);

			int choice2;  //getLine은 스트링만 받을 수 있구나?
			cout << "계속 검색하시겠습니까? : ";
			cout << "yes =1 , no = 0 " << "\n";
			cin >> choice2;
			if (cin.fail() || (choice2 != 0 && choice2 != 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 0 또는 1를 입력하세요!" << endl;
				cout << "초기화면으로 돌아갑니다 " << endl;
				continue;
			}

			if (choice2 == 1) {
				while (1) {
					printBoundary();
					string title;
					cout << "검색할 책 제목: ";
					cin.ignore();
					getline(cin, title);
					cout << "title : " << title << "\n";
					m->getBookByTitle(title);

					int choice3;
					cout << "계속 검색하시겠습니까? : " << "\n";
					cout << "no =0 , yes = 1 ";

					cin >> choice3;

					if (cin.fail() || (choice3 != 0 && choice3 != 1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "잘못된 입력입니다. 0 또는 1를 입력하세요!" << endl;
						continue;
					}

					if (choice3 == 0) break;
				}
			}
		}

		else if (choice == 4) {
			printBoundary();
			cout << "작가 검색 입니다 " << endl;
			//작가 검색
			string author;
			cout << "검색할 책 제목: ";
			cin.ignore();
			getline(cin, author);
			m->getBookByAuthor(author);
			int choice2;  //getLine은 스트링만 받을 수 있구나?
			cout << "계속 검색하시겠습니까? : ";
			cout << "yes =1 , no = 0 ";
			cin >> choice2;
			if (cin.fail() || (choice2 != 0 && choice2 != 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "잘못된 입력입니다. 0 또는 1를 입력하세요!" << endl;
				cout << "초기화면으로 돌아갑니다 " << endl;
				continue;
			}
			if (choice2 == 1) {
				while (1) {
					printBoundary();
					string author;
					Book* result;

					cout << "검색할 책 제목: ";
					int breakpoint = 100;
					cin.ignore();
					getline(cin, author);



					result = m->getBookByAuthor(author);
					//result를 안써도 되지만 공부를 위해 추가했습니다.

					if (result == nullptr)
					{

						cout << "올바르지 않은 입력이거나 책을 찾을 수 없습니다! _searchAuthor" << endl;
						cout << "다시 입력해주세요" << endl;

						cout << "초기화면으로 돌아갑니다  " << endl;
						break;


					}
					else {
						int choice3;
						cout << "result is  : " << result->title << result->author << endl;
						cout << "계속 검색하시겠습니까? : ";
						cout << "no =0 , yes = 1 ";

						cin >> choice3;
						if (cin.fail() || (choice3 != 0 && choice3 != 1)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "잘못된 입력입니다. 0 또는 1를 입력하세요!" << endl;
							continue;
						}

						if (choice3 == 0) break;


					}

				}
			}

		}
		else if (choice == 5) {
	
			// 대여 문의
			// 계속 빌리시려면 1번 아니라면 0번을 눌러주세요
			// 

			string author;
			string title;

			int choice2 = 0;

			while (1) {
				printBoundary();
				
				cout << "어서오세요 대여센터 입니다 " << endl;
				cout << "책 목록은 3개까지만 띄워드립니다." << endl;
				b.displayStock(3);
				cout << "자세한 목록은 7번 센터로 가주세요~ " << endl;
				cout << "책 검색 : 1 , 작가 검색 : 2 , 초기 화면 : 0 을 눌러주세요 :";
				cin >> choice2;

				if (cin.fail() || (choice2 != 0 && choice2 != 1 && choice2 != 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "잘못된 입력입니다. 0 또는 1 또는 2를 입력하세요!" << endl;
					continue;
				}

				if (choice2 == 1) {
					cin.ignore();
					cout << "대여하실 책 제목: ";
					getline(cin, title);
					b.borrowBookBytitle(title);
					continue;

				}
				if (choice2 == 2) {
					cin.ignore();
					cout << "대여하실 작가 이름: ";
					getline(cin, author);
					b.borrowBookByAuthor(author, m);

					continue;
				}
				if (choice2 == 0) {
					break;
				}

			}

			//마지막에는 공백 남겨줘야한다.
		}
		else if (choice == 6) { // 반납 문의

			printBoundary();
			cout << "어서오세요 반납센터 입니다 " << endl;
			string author;
			string title;

			int choice2 = 0;

			while (1) {
				printBoundary();
				cout << "반납 하실 책 검색을 활용 해주세요 " << endl;
				cout << "책 검색 : 1 , 작가 검색 : 2 , 초기 화면 : 0 을 눌러주세요 :";
				cin >> choice2;

				if (cin.fail() || (choice2 != 0 && choice2 != 1 && choice2 != 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "잘못된 입력입니다. 0 또는 1 또는 2를 입력하세요!" << endl;
					continue;
				}

				if (choice2 == 1) {
					cin.ignore();
					cout << "반납하실 책 제목: ";
					getline(cin, title);
					b.returnBookTitle(title);
					continue;

				}
				if (choice2 == 2) {
					cin.ignore();
					cout << "반납하실 작가 이름: ";
					getline(cin, author);
					b.returnBookAuthor(author, m);

					continue;
				}
				if (choice2 == 0) {
					break;
				}

			}

		}
		else if (choice == 7) {
			printBoundary();
			cout << "어서오세요 대여 가능 목록을 보여드려요 " << endl;
			b.displayStock(b.getStockSize());
		}
		else if (choice == 0) {
			// 0번 선택: 종료
			// 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
			cout << "프로그램을 종료합니다." << endl;
			break; // while 루프 종료
		}


		//else {
		//    // 잘못된 입력 처리
		//    // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
		//    cout << "잘못된 입력입니다. 초기화면으로 돌아갑니다" << endl;
		//  
		//}
	}

	return 0; // 프로그램 정상 종료
}








