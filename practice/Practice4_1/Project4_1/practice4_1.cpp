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
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(string title) {
        //��� for������ ���Ƶ� �ɰͰ����ѵ�..
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

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�" << endl; // ���α׷� ����
        cout << "4. �۰� �˻�" << endl; // ���α׷� ����
        cout << "5. ����" << endl; // ���α׷� ����

        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
           // ���� ����
            //å�˻�
            string title; 
            cout << "�˻��� å ����: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
            int choice2;  //getLine�� ��Ʈ���� ���� �� �ֱ���?
            cout << "��� �˻��Ͻðڽ��ϱ�? : ";
            cout << "yes =1 , no = 0 "<<"\n";
            cin >> choice2;
            if (choice2 == 1) {
                while (1) {
                    string title;
                    cout << "�˻��� å ����: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "title : " << title << "\n";
                    manager.searchByTitle(title);
                    int choice2;
                    cout << "��� �˻��Ͻðڽ��ϱ�? : "<<"\n";
                    cout << "yes =1 , no = 0 " ;

                    cin >> choice2;
                    if (choice2 == 0) break;
                }
            }
        }
        else if (choice == 4) {
            //�۰� �˻�
            string author;
            cout << "�˻��� å ����: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
            int choice2;  //getLine�� ��Ʈ���� ���� �� �ֱ���?
            cout << "��� �˻��Ͻðڽ��ϱ�? : ";
            cout << "yes =1 , no = 0 "; 
            cin >>  choice2;
            // �̰� �Ƚᵵ �ɰͰ�����? ���ϵ��� �����ϸ鼭 �� ���� �԰���ϱ�cin.ignore();
            if (choice2 == 1) {
                while (1) {
                    string author;
                    cout << "�˻��� å ����: ";
                    cin.ignore();
                    getline(cin, author);
                    cout << "author : " << author << "\n";
                    manager.searchByAuthor(author);
                    int choice2;
                    cout << "��� �˻��Ͻðڽ��ϱ�? : ";
                    cout << "yes =1 , no = 0 ";
                    
                    cin >> choice2;
                    if (choice2 == 0) break;
                }
            }
            //��� �˻��� ���ϸ� ���⿡ �ְ�
            // �װ� �ƴ϶�� ������ 
        }
        else if (choice == 5) {
            // 5�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. ���α׷��� ����˴ϴ�." << endl;
            break;
        }
    }

    return 0; // ���α׷� ���� ����
}