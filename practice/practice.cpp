#include <iostream>
using namespace std;




int Sum(int* sum, int size) {
    int sum1 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += sum[i];
    }
    return sum1;
}

double Avg(int sum, int size) {
    return (double)sum / size;
}

void Sort(int* sum, int size, int type) {
    printf("throw\n");
    int tmp = 0;

    if (type == 0) {

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {

                if (sum[j] > sum[j + 1]) {
                    cout << "first : " << sum[j] << " " << sum[j + 1] << endl;
                    tmp = sum[j];
                    sum[j] = sum[j + 1];
                    sum[j + 1] = tmp;

                    cout << "change is : " << sum[j] << " " << sum[j + 1] << endl;
                }

            }
        }
    }
    if (type == 1) {

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - -i - 1; j++) {
                if (sum[j] < sum[j + 1]) {
                    tmp = sum[j];
                    sum[j] = sum[j + 1];
                    sum[j + 1] = tmp;

                }


            }
        }
    }

}

void printArray(int* sum, int size) {
    for (int i = 0; i < size; i++) {
        cout << sum[i] << " ";
    }
    cout << endl;
}

int main() {
    int num[5] = { 0 };
    int type = -1;

    for (int i = 0; i < 5; i++) {
        cout << "숫자를 입력해주세요 : ";
        cin >> num[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << num[i] << " ";

    }
    cout << endl;

    cout << "Sum : " << Sum(num, 5) << " "
        << "Avg : " << Avg(Sum(num, 5), 5);
    cout << endl;
    cout << "Type Code :  0 = 오름차순 , 1 = 내림차순 " << endl;
    cout << "Type을 입력해주세요 : ";
    cin >> type;
    Sort(num, 5, type);
    cout << "결과를 확인하세요" << endl;
    printArray(num, 5);


    return 0;
}