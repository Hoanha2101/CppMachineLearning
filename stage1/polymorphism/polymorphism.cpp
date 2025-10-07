#include <iostream>
#include <string>
using namespace std;

class Animal {
    public:
        // Nếu không có virtual, ta sẽ luôn gọi hàm của lớp cha.
        virtual void sound () {
            cout << "Animal sound" << endl;
        };
};

class Dog : public Animal {
    public: 
        void sound () {
            cout << "Gau gau" << endl;
        };
};

class Cat : public Animal {
    public: 
        void sound () {
            cout << "Meo meo" << endl;
        };
};

int main() {
    Animal *a1 = new Dog();
    Animal *a2 = new Cat();

    a1->sound();
    a2->sound();   

    delete a1;
    delete a2;

}