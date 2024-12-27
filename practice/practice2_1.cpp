


#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal������" << endl;
    }

    virtual void makeSound() = 0;

    ~Animal() {
        cout << "Animal�Ҹ���" << endl;

    }
};

class Dog : public Animal {

public:
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
class Cat : public Animal {

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

class Cow : public Animal {

public:
    Cow() {
        cout << "Cow������" << endl;
    }
    void makeSound() {
        cout << "Cow" << endl;
    }
    ~Cow() {
        cout << "Cow�Ҹ���" << endl;
    }
};

void printAnimal(Animal** a, int size) { //Animal **a //Animal *a[]
    
    for (int i = 0; i < size; i++) {
        a[i]->makeSound();
    }
}


int main() {

    Animal* myAnimal[3];
    
    myAnimal[0] = new Dog();
    myAnimal[1] = new Cat();
    myAnimal[2] = new Cow();
    
    printAnimal(myAnimal, 3);

    for (int i = 0; i < 3; i++) {
        delete myAnimal[i];
    }

    return 0;
}
