#include <iostream>
using namespace std;

class Animal {
public : 
    Animal() {
        cout << "Animal持失切" << endl;
    }

    void makeSound() = 0;

    ~Animal() {
        cout << "Animal社瑚切" << endl;

    }
};

class Dog : Animal {

public : 
    Dog() {
        cout << "Dog持失切" << endl;
    }
    void makeSound() {
        cout << "Dog" << endl;
    }
    ~Dog() {
        cout << "Dog社瑚切" << endl;
    }

};
class Cat : Animal {

public:
    Cat() {
        cout << "Cat持失切" << endl;
    }
    void makeSound() {
        cout << "Cat" << endl;
    }
    ~Cat() {
        cout << "Cat社瑚切" << endl;
    }
};

class Cow : Animal {

public:
    Cow() {
        cout << "Cow持失切" << endl;
    }
    void makeSound() {
        cout << "Cow" << endl;
    }
    ~Cat() {
        cout << "Cow社瑚切" << endl;
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