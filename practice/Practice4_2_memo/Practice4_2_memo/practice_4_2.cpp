


/////////////////////////////////////////
/**4-2*/
//////////////////////////////////////////

/**
���� ���
1. Ư�� å�� �뿩 ���θ� �˾ƾ��Ѵ�
2. å�� �̸����� �뿩 ���θ� �˻��ϰ�, �뿩�� �ƴ� ��� �뿩�� �� �־���Ѵ�
3. å�� �۰��� �뿩 ����
4. å�� �ݳ��� �� �־���Ѵ�.
5. å�� ���� 3������ ����
*/

/** ����4 PIL
* 1. �ʹ� Ŭ���� �ȿ� �������Ѽ� ������ �ߴ� =>���ο��� ���� �޾ƿͼ� �ص� �Ǵµ� ���ο��� �޴� ����� �������� �ʾҽ��ϴ�.
* 2. Ŭ���� ���̾�׷��� ������ �䱸�ϴ��� ������ �Խ��ϴ�. �ϸŴ����� �� �׸��� �������ڴ� ���θ� ������մϴ�.
* 3. ������ �䱸�ϴ� �ٸ� ������, ���� �������ڿ��� �ϸŴ����� ȣ���ϴ� ��찡 ����ٸ� �׶��� ���յ��� �ö󰩴ϴ�.
* 4. ���ΰ� �����̴� ��ŭ �������ڰ� �ϸŴ����� ȣ���ϴ� ��츦 �����Ͽ� ���յ��� ���ߴ� ����� �����غ��ҽ��ϴ�.
*    ���� �������ڰ� �۰��� �̸��� ���� ���, �ϸŴ����� ȣ���ϴ� ����� ���� ����Ͽ����ϴ�.
*    �������̽��� ���� �� �����Լ����� �������� �ٷ�� ����
*    ����� �۰��̸� �Է� -> manager �� ��ȯ -> å�� ���� ���� -> ������ ȣ��
* 5. ���� �������̽��� �ϳ� ����� ���յ��� �������ٴ� ���� �˰ԵǾ����ϴ�.
* 6. ���� �̹� ������ ������ �䱸���׵� �����԰� ���ÿ� �������̽��� �����Ͽ� ���յ��� ���ߴ� �������� ����� �մϴ�.
* 7. nullptr�� ����ó���ϴµ� �־� , try catch�� �����غý��ϴ�.
* 8. get,Find
* 9. TIL�� ���� �ؾ��� �� : Const, ����Ʈ ������ ,auto , for�� ���׷��̵� , & , try catch,
*                         main�Լ� ���� result�� �޴� �κ�  ,cin
* get = ó������ Ȯ�强�� ���� ������°ǰ�?��� ������ �����.
		 �ᱹ���� ���� ���� ���ڿ� �Ľ� �� ������ ������ �����ϴ°�
		 ���� find������ �ᱹ ���� å���� �ǵ�� ������ private ����

* find = find�� ������ ���� ������ ���� ���ڿ��̸� �̰����� nullptr�� ��ȯ�� ã�� å�� ����
*
		main�Լ����� 3���� 4���� ������ �� )
		Book *m1  = getBookByTitle (); �� ������ ��
		if (m1 == nullptr)
		{
			cout << "�ùٸ��� ���� �Է��Դϴ�_main !" << endl;

		}
		�ش� �Լ��� ������� �ʾƵ� getBookByTitle�ȿ���
		����ó���� �Ѵ�
		�׷��� ������ �����Լ��ȿ���  m1�� ������� �ʴ´ٸ�
		null�� ���ϵǰ� null�� �����ϴ� ���� ����
		�׷��� ���� �̰� ���� �ڵ��ΰ�?
		�����Լ����� ����ϴ� ����� ó���� ������ϴ� ��������
		�ش� getBookByTitle�Լ��� ��쿡��
		�� �Ŵ����� �������� main �ٸ� �Լ��� ó���Ǳ� ������
		���� �� �ʿ䰡 ���
		nullptr�� ó������ �ʿ䰡 ����
		�̷��ǹ̿����� ���θ� �� �� ���� �ϴ°� �����ǰ�?

		������ ��� case4������ ����ؼ��� �ȵȴ� .

		���� :  result�� �޾ƿͼ� ���� �������� result->�� ���� �����̴�
			   �ٽø��� result�� �� ������ �ؼ��� �ȵȴ�.

*/


/**
*
* 2. �� cin�� choice2�� �޴µ� ���ڰ� ���� ���ۺ��� ���ѷ���  ������
TODO : �ݳ� �뿩 ���� �ۼ� 1��30�б��� ������

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
	vector<Book> books; // å ��� ����

	Book* findBookByTitle(const string& title) {



		for (vector<Book>::iterator it2 = books.begin();
			it2 != books.end();
			it2++
			)
		{

			if (it2->title == title) {
				cout << "title exist" << endl;
				//���⼭ ������ �� �ؾ�����?
				return  &(*it2);
			}

		}
		// get�� ȣ���ϱ� ������ ���ܻ���ó��
		cout << "�ش� å�� �����ϴ�" << endl;

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
		//get�� ȣ���ϱ� ������ ���ܻ���ó��
		cout << "�ش� å�� �����ϴ�" << endl;
		//���ݱ��� �Ѿ�Դٴ°� return�� ���ߴٴ� �Ҹ��̰�, ã�� ���� ���ٴ� �Ҹ�
		return nullptr;

	}
public:
	// å �߰� �޼���
	void addBook(const string& title, const string& author) override {
		if (title.length() >= 20 || author.length() >= 20) {
			cout << "Input Length Error" << endl;
			return;
		}
		books.push_back(Book(title, author)); // push_back ���
		cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
	}

	// ��� å ��� �޼���
	void displayAllBooks() const override {
		if (books.empty()) {
			cout << "���� ��ϵ� å�� �����ϴ�." << endl;
			return;
		}

		cout << "���� ���� ���:" << endl;
		for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
			cout << "- " << books[i].title << " by " << books[i].author << endl;
		}
	}


	Book* getBookByTitle(const string& title)  override {
		//title ��ȿ�� ����
		//���ǻ� ���̰� 20�� �ʰ��ϸ� return 
		try {
			if (title.length() >= 20) {
				throw invalid_argument("�۰��� �̸��� 20�ڸ� �ʰ��մϴ�: Early Exit");
			}
			Book* tmp = findBookByTitle(title);
			if (tmp == nullptr) {
				throw runtime_error("�ش� �۰��� å�� ã�� �� �����ϴ�.");
			}

			return tmp;
		}
		catch (const exception& e) {
			cerr << "���� : " << e.what() << endl;
			return nullptr;
		}
	}

	// �̰� dangling pointer������
	// ����Ʈ�����ͻ���ؾ��ϳ�? 



	Book* getBookByAuthor(const string& author) override {


		try {
			// ��ȿ�� �˻�: �۰� �̸� ���̰� 20 �̻��̸� ���� ó��
			if (author.length() >= 20) {
				throw invalid_argument("�۰��� �̸��� 20�ڸ� �ʰ��մϴ�: Early Exit");
			}

			// å �˻�
			Book* tmp = findBookByAuthor(author);

			// �˻� ����� ������ ���� �߻�
			if (tmp == nullptr) {
				throw runtime_error("�ش� �۰��� å�� ã�� �� �����ϴ�.");
			}

			// �˻� ����
			return tmp;

		}
		catch (const exception& e) {
			// ���� �޽��� ���
			cerr << "����: " << e.what() << endl;
			return nullptr; // ���� �߻� �� nullptr ��ȯ
		}

	}


	/**��� �ȴ� ������ ���θ� ���� ���ܵ��� , ���ͷ� �� �ޱ⺸�ٴ�
	main���� add�Ҷ����� initialize ���ָ�ȴ� */
	const vector<Book>& getAllBooks() const override {
		return books;
	}

};

class BorrowManager {
private:
	unordered_map<string, int> stock;
	//������� ���� borrow�� ���� ��� �����ϰ� �غ��� 

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
			cout << " �ش� å�� �������� �ʽ��ϴ�. ����� �Է����ּ��� " << endl;
		}

		else if (it != stock.end()) {
			if (it->second == 0) {
				cout << "�뿩 ������ å�� �����ϴ�. ������ �ٽ� ã�ƿ�����" << endl;
			}
			else {
				cout << "�뿩 �Ϸ� " << endl;
				it->second--;
				cout << "�뿩 �� å " << title << "�� ���� ���� : " << it->second << endl;
			}

		}

	}

	void borrowBookByAuthor(const string& author, IBookManager* m1) {
		Book* b;
		b = m1->getBookByAuthor(author);
		if (b == nullptr)
		{
			cout << "�ùٸ��� ���� �Է��Դϴ� !" << endl;

		}
		else {
			unordered_map<string, int>::iterator it = stock.find(b->title);
			if (it == stock.end()) {
				cout << " �ش� å�� �������� �ʽ��ϴ�. ����� �Է����ּ��� " << endl;
			}

			else if (it != stock.end()) {
				if (it->second == 0) {
					cout << "�뿩 ������ å�� �����ϴ�. ������ �ٽ� ã�ƿ�����" << endl;
				}
				else {
					cout << "�뿩 �Ϸ� " << endl;
					it->second--;
					cout << "�뿩 �� �۰� : " << b->author << "   ��" << "å " << b->title << "�� ���� ���� : " << it->second << endl;
				}

			}
		}

	}

	void returnBookTitle(const string& title) {
		unordered_map<string, int>::iterator it = stock.find(title);
		if (it == stock.end()) {
			cout << " �ش� å�� �������� �ʽ��ϴ�. ����� �Է����ּ��� " << endl;
		}

		else if (it != stock.end()) {
			if (it->second == 3) {
				cout << "�ݳ� ������ å�� �����ϴ�.��� ���������� ���Ŀ°���?! " << endl;
			}
			else {
				cout << "�ݳ� �Ϸ� " << endl;
				it->second++;
				cout << "�ݳ� �� å " << title << "�� ���� ���� : " << it->second << endl;
			}

		}
	}
	void returnBookAuthor(const string& author, IBookManager* m1) {
		Book* b;
		b = m1->getBookByAuthor(author);
		if (b == nullptr) cout << "�ùٸ��� ���� �Է��Դϴ� !" << endl;
		else {
			unordered_map<string, int>::iterator it = stock.find(b->title);
			if (it == stock.end()) {
				cout << " �ش� å�� �������� �ʽ��ϴ�. ����� �Է����ּ��� " << endl;
			}

			else if (it != stock.end()) {
				if (it->second == 3) {
					cout << "�ݳ� ������ å�� �����ϴ�.��� ���������� ���Ŀ°���?! " << endl;
				}
				else {
					cout << "�ݳ� �Ϸ� " << endl;
					it->second++;
					cout << "�ݳ� �� �۰� : " << b->author << "   ��" << "å " << b->title << "�� ���� ���� : " << it->second << endl;
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
			cout << "å �̸� : " << it->first << " - " << "���� ���� : " << it->second << endl;
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

	// ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
	// ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
	while (true) {
		cout << "\n������ ���� ���α׷�" << endl;
		cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
		cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
		cout << "3. å �˻�" << endl; // ���α׷� ����
		cout << "4. �۰� �˻�" << endl; // ���α׷� ����
		cout << "5. å �뿩 ����" << endl;
		cout << "6. å �ݳ� ����" << endl;
		cout << "7. å �뿩 ���� ���" << endl;
		cout << "0. ����" << endl; // ���α׷� ����

		cout << "����: ";

		int choice; // ������� �޴� ������ ����
		cin >> choice;
		if (cin.fail() || (choice != 0 && choice != 1
			&& choice != 2 && choice != 3 && choice != 4
			&& choice != 5 && choice != 6 && choice != 7
			)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�߸��� �Է��Դϴ�. �ùٸ� ���� �Է��ϼ��� !" << endl;
			continue;
		}


		if (choice == 1) {
			printBoundary();
			cout << "å �߰��Ͻ÷�����?? ������� ����� ���� :)" << endl;
			// 1�� ����: å �߰�
			// ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
			string title, author;
			cout << "å ����: ";
			cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
			getline(cin, title); // ���� �Է� (���� ����)
			cout << "å ����: ";
			getline(cin, author); // ���ڸ� �Է� (���� ����)
			m->addBook(title, author); // �Է¹��� å ������ �߰�
			b.initializeStock(title);
		}
		else if (choice == 2) {
			printBoundary();
			cout << "å ��� �˻��Դϴ� " << endl;
			// 2�� ����: ��� å ���
			// ���� BookManager�� ����� å ����� ����մϴ�.
			m->displayAllBooks();
		}
		else if (choice == 3) {
			printBoundary();
			cout << "���� �˻� �Դϴ�" << endl;
			// ���� ����
			 //å�˻�
			string title;
			cout << "�˻��� å ����: ";
			cin.ignore();
			getline(cin, title);
			m->getBookByTitle(title);

			int choice2;  //getLine�� ��Ʈ���� ���� �� �ֱ���?
			cout << "��� �˻��Ͻðڽ��ϱ�? : ";
			cout << "yes =1 , no = 0 " << "\n";
			cin >> choice2;
			if (cin.fail() || (choice2 != 0 && choice2 != 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���!" << endl;
				cout << "�ʱ�ȭ������ ���ư��ϴ� " << endl;
				continue;
			}

			if (choice2 == 1) {
				while (1) {
					printBoundary();
					string title;
					cout << "�˻��� å ����: ";
					cin.ignore();
					getline(cin, title);
					cout << "title : " << title << "\n";
					m->getBookByTitle(title);

					int choice3;
					cout << "��� �˻��Ͻðڽ��ϱ�? : " << "\n";
					cout << "no =0 , yes = 1 ";

					cin >> choice3;

					if (cin.fail() || (choice3 != 0 && choice3 != 1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���!" << endl;
						continue;
					}

					if (choice3 == 0) break;
				}
			}
		}

		else if (choice == 4) {
			printBoundary();
			cout << "�۰� �˻� �Դϴ� " << endl;
			//�۰� �˻�
			string author;
			cout << "�˻��� å ����: ";
			cin.ignore();
			getline(cin, author);
			m->getBookByAuthor(author);
			int choice2;  //getLine�� ��Ʈ���� ���� �� �ֱ���?
			cout << "��� �˻��Ͻðڽ��ϱ�? : ";
			cout << "yes =1 , no = 0 ";
			cin >> choice2;
			if (cin.fail() || (choice2 != 0 && choice2 != 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���!" << endl;
				cout << "�ʱ�ȭ������ ���ư��ϴ� " << endl;
				continue;
			}
			if (choice2 == 1) {
				while (1) {
					printBoundary();
					string author;
					Book* result;

					cout << "�˻��� å ����: ";
					int breakpoint = 100;
					cin.ignore();
					getline(cin, author);



					result = m->getBookByAuthor(author);
					//result�� �Ƚᵵ ������ ���θ� ���� �߰��߽��ϴ�.

					if (result == nullptr)
					{

						cout << "�ùٸ��� ���� �Է��̰ų� å�� ã�� �� �����ϴ�! _searchAuthor" << endl;
						cout << "�ٽ� �Է����ּ���" << endl;

						cout << "�ʱ�ȭ������ ���ư��ϴ�  " << endl;
						break;


					}
					else {
						int choice3;
						cout << "result is  : " << result->title << result->author << endl;
						cout << "��� �˻��Ͻðڽ��ϱ�? : ";
						cout << "no =0 , yes = 1 ";

						cin >> choice3;
						if (cin.fail() || (choice3 != 0 && choice3 != 1)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1�� �Է��ϼ���!" << endl;
							continue;
						}

						if (choice3 == 0) break;


					}

				}
			}

		}
		else if (choice == 5) {
	
			// �뿩 ����
			// ��� �����÷��� 1�� �ƴ϶�� 0���� �����ּ���
			// 

			string author;
			string title;

			int choice2 = 0;

			while (1) {
				printBoundary();
				
				cout << "������� �뿩���� �Դϴ� " << endl;
				cout << "å ����� 3�������� ����帳�ϴ�." << endl;
				b.displayStock(3);
				cout << "�ڼ��� ����� 7�� ���ͷ� ���ּ���~ " << endl;
				cout << "å �˻� : 1 , �۰� �˻� : 2 , �ʱ� ȭ�� : 0 �� �����ּ��� :";
				cin >> choice2;

				if (cin.fail() || (choice2 != 0 && choice2 != 1 && choice2 != 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1 �Ǵ� 2�� �Է��ϼ���!" << endl;
					continue;
				}

				if (choice2 == 1) {
					cin.ignore();
					cout << "�뿩�Ͻ� å ����: ";
					getline(cin, title);
					b.borrowBookBytitle(title);
					continue;

				}
				if (choice2 == 2) {
					cin.ignore();
					cout << "�뿩�Ͻ� �۰� �̸�: ";
					getline(cin, author);
					b.borrowBookByAuthor(author, m);

					continue;
				}
				if (choice2 == 0) {
					break;
				}

			}

			//���������� ���� ��������Ѵ�.
		}
		else if (choice == 6) { // �ݳ� ����

			printBoundary();
			cout << "������� �ݳ����� �Դϴ� " << endl;
			string author;
			string title;

			int choice2 = 0;

			while (1) {
				printBoundary();
				cout << "�ݳ� �Ͻ� å �˻��� Ȱ�� ���ּ��� " << endl;
				cout << "å �˻� : 1 , �۰� �˻� : 2 , �ʱ� ȭ�� : 0 �� �����ּ��� :";
				cin >> choice2;

				if (cin.fail() || (choice2 != 0 && choice2 != 1 && choice2 != 2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "�߸��� �Է��Դϴ�. 0 �Ǵ� 1 �Ǵ� 2�� �Է��ϼ���!" << endl;
					continue;
				}

				if (choice2 == 1) {
					cin.ignore();
					cout << "�ݳ��Ͻ� å ����: ";
					getline(cin, title);
					b.returnBookTitle(title);
					continue;

				}
				if (choice2 == 2) {
					cin.ignore();
					cout << "�ݳ��Ͻ� �۰� �̸�: ";
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
			cout << "������� �뿩 ���� ����� ��������� " << endl;
			b.displayStock(b.getStockSize());
		}
		else if (choice == 0) {
			// 0�� ����: ����
			// ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
			cout << "���α׷��� �����մϴ�." << endl;
			break; // while ���� ����
		}


		//else {
		//    // �߸��� �Է� ó��
		//    // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
		//    cout << "�߸��� �Է��Դϴ�. �ʱ�ȭ������ ���ư��ϴ�" << endl;
		//  
		//}
	}

	return 0; // ���α׷� ���� ����
}








