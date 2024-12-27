#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> 
using namespace std;


class Animal {
public:
    Animal() {
        cout << "Animal생성자" << endl;
    }

    virtual void makeSound() = 0;

    ~Animal() {
        cout << "Animal소멸자" << endl;

    }
};

class Dog : public Animal {

public:
    Dog() {
        cout << "Dog생성자" << endl;
    }
    void makeSound() {
        cout << "Dog" << endl;
    }
    ~Dog() {
        cout << "Dog소멸자" << endl;
    }

};
class Cat : public Animal {

public:
    Cat() {
        cout << "Cat생성자" << endl;
    }
    void makeSound() {
        cout << "Cat" << endl;
    }
    ~Cat() {
        cout << "Cat소멸자" << endl;
    }
};

class Cow : public Animal {

public:
    Cow() {
        cout << "Cow생성자" << endl;
    }
    void makeSound() {
        cout << "Cow" << endl;
    }
    ~Cow() {
        cout << "Cow소멸자" << endl;
    }
};


void printAnimal(Animal** a, int size) { //Animal **a //Animal *a[]

    for (int i = 0; i < size; i++) {
        a[i]->makeSound();
    }
}

void initializeRandom() {

    srand(static_cast<unsigned int>(time(0)));
}


int generateRandom(int min, int max) {

    return min + (rand() % (max - min + 1));
}

Animal* createRandomAnimal(Animal* animal) {

    int j = generateRandom(0, 2);
    cout << "현재 랜덤변수는 다음과 같습니다 : " << j << endl;

    if (j == 0) {
        return new Dog;
    }
    if (j == 1) {
        return new Cat;
    }
    if (j == 2) {
        return new Cow;
    }
    else return 0;
}



class Zoo {
private:
    Animal* animals[10];
    int animalCnt;
public:
    Zoo() {
        cout << "Z 생성자 시작 " << endl;
        for (int i = 0; i < 10; i++) {
            animals[i] = NULL;

        }
        animalCnt = 0;
    }
    void addAnimal(Animal* animal) {
        if (animal == NULL) { cout << "Zoo addAnimal receive NULL" << endl; }
        else {
            cout << "first time we see animalCnt = " << this->animalCnt << endl;

            this->animals[this->animalCnt] = animal;

            cout << "and we see animal's sound";
            this->animals[this->animalCnt]->makeSound();

            this->animalCnt++;
        }
    }
    void performActions() {
        for (int i = 0; i < animalCnt; i++) {
            this->animals[i]->makeSound();
        }
    }
    ~Zoo() {

        for (int i = 0; i < animalCnt; i++) {
            delete animals[i];
            cout << i << "번째 animal 삭제중 " << endl;
        }
        cout << "Zoo 소멸" << endl;
    }
};








int main() {



    Zoo* test = new Zoo();
    Animal* a = NULL;
    Animal* tmp = NULL;




    initializeRandom();

    for (int i = 0; i < 10; i++) {
        tmp = createRandomAnimal(a);
        if (tmp != NULL) {

            cout << "tmp에 들어간 값은 다음과 같습니다 : ";
            tmp->makeSound();

            test->addAnimal(tmp);
        }
        if (tmp == NULL) { return -1; }

    }

    cout << "저장이 완료 되었습니다." << endl;

    test->performActions();

    delete test;


    return 0;
}

