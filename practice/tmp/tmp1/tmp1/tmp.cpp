#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Observer �������̽�
// - Observer ���Ͽ��� ���� ��ȭ�� �˸��޴� ��ü���� ���� �������̽�
// - Observer���� �� �������̽��� �����Ͽ� `update` �޼��带 ���� �����͸� ���޹���
class Observer {
public:
    virtual ~Observer() = default;               // ���� �Ҹ���
    virtual void update(int data) = 0;           // ������ ������Ʈ �޼��� (���� ���� �Լ�)
};

// Subject Ŭ���� (���� ��Ʈ ����)
// - �������� ���� ��ȭ�� �����ϸ�, ��� ��ϵ� Observer�鿡�� ���� ������ �˸�
class ExcelSheet {
private:
    vector<Observer*> observers;                 // Observer���� �����ϴ� ����Ʈ
    int data;                                    // ���� ������ ����

public:
    ExcelSheet() : data(0) {}                    // ������: �ʱ� ������ ���� 0

    // Observer ��� �޼���
    // - ���ο� Observer�� ����Ͽ� ���� ���� �˸��� ���� �� �ֵ��� �߰�
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    // ������ ���� �˸� �޼���
    // - ��ϵ� ��� Observer���� `update` �޼��带 ȣ���Ͽ� ������ ���� ������ �˸�
    void notify() {
        for (Observer* observer : observers) {
            observer->update(data);              // �� Observer���� �����͸� ����
        }
    }

    // ������ ���� �޼���
    // - �����͸� �����ϰ� ���� ������ ��� Observer���� �˸�
    void setData(int newData) {
        data = newData;                          // ���ο� �����ͷ� ����
        cout << "ExcelSheet: Data updated to " << data << endl;
        notify();                                // Observer�鿡�� �˸�
    }
};

// ��ü���� Observer Ŭ����: BarChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class BarChart : public Observer {
public:
    void update(int data) {                      // ������ ������Ʈ �� ȣ���
        cout << "BarChart: Displaying data as vertical bars: ";
        for (int i = 0; i < data; ++i) {
            cout << "|";                         // ������ ����ŭ ���� ���
        }
        cout << " (" << data << ")" << endl;
    }
};

// ��ü���� Observer Ŭ����: LineChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class LineChart : public Observer {
public:
    void update(int data) {                      // ������ ������Ʈ �� ȣ���
        cout << "LineChart: Plotting data as a line: ";
        for (int i = 0; i < data; ++i) {
            cout << "-";                         // ������ ����ŭ �� ���
        }
        cout << " (" << data << ")" << endl;
    }
};

// ��ü���� Observer Ŭ����: PieChart (���� ��Ʈ)
// - �����͸� ���� �׷����� ǥ��
class PieChart : public Observer {
public:
    void update(int data) {                      // ������ ������Ʈ �� ȣ���
        cout << "PieChart: Displaying data as a pie chart slice: ";
        cout << "Pie [" << data << "%]" << endl; // ������ �� ��� (����: % ������ ǥ��)
    }
};

// ���� �Լ�
int main() {
    
    cout << 10 % 3 << endl;

    return 0;
}

/**
class Observer {
public:
    virtual ~Observer() = default;               // ���� �Ҹ���
    virtual void update(int data) = 0;           // ������ ������Ʈ �޼��� (���� ���� �Լ�)
}; ���⿡�� �긦 ��� ���ص� �����ִ� ����������? ���������Լ��ε�, �ڿ��� �ݵ�� ������ �������
*/