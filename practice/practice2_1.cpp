


#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Animal持失切" << endl;
    }

    virtual void makeSound() = 0;

    ~Animal() {
        cout << "Animal社瑚切" << endl;

    }
};

class Dog : public Animal {

public:
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
class Cat : public Animal {

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

class Cow : public Animal {

public:
    Cow() {
        cout << "Cow持失切" << endl;
    }
    void makeSound() {
        cout << "Cow" << endl;
    }
    ~Cow() {
        cout << "Cow社瑚切" << endl;
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
