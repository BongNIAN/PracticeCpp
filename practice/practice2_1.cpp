#include <iostream>
using namespace std;

class Animal {
public : 
    Animal() {
        cout << "Animal������" << endl;
    }

    void makeSound() = 0;

    ~Animal() {
        cout << "Animal�Ҹ���" << endl;

    }
};

class Dog : Animal {

public : 
    Dog() {
        cout << "Dog������" << endl;
    }
    void makeSound() {
        cout << "Dog" << endl;
    }
    ~Dog() {
        cout << "Dog�Ҹ���" << endl;
    }

};
class Cat : Animal {

public:
    Cat() {
        cout << "Cat������" << endl;
    }
    void makeSound() {
        cout << "Cat" << endl;
    }
    ~Cat() {
        cout << "Cat�Ҹ���" << endl;
    }
};

class Cow : Animal {

public:
    Cow() {
        cout << "Cow������" << endl;
    }
    void makeSound() {
        cout << "Cow" << endl;
    }
    ~Cat() {
        cout << "Cow�Ҹ���" << endl;
    }
};

void printAnimal(animal *a[],int size) {

}


int main() {
    Animal* p[3] = animal;
    p[0] = &Dog;
    p[1] = &Cat;
    p[2] = &Cow;

    return 0;
}