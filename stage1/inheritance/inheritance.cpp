#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
        string name;
        int age;
    public:
        Person(string n, int a): name(n), age(a) {};

        void showInfo() {
            cout << "Thong tin: " << name << " - " << age << endl; 
        };
};

class Student : public Person {
    protected:
        string major;
    public:
        Student(string n, int a, string m)
        : Person(n, a), major(m) {};
        void showInfo() {
            cout << "Sinh vien: " << name << " - " << age << " - " << major;
        };
};

class AIStudent : public Student {
    private:
        float gpa;
    public:
        AIStudent(string n, int a, string m, float g)
        : Student(n, a, m), gpa(g) {};

        void showInfo() {
            cout << "AI Student: " << name
             << ", Nganh: " << major
             << ", GPA: " << gpa << endl;
        };
};

int main() {
    AIStudent hoan("Hoan", 21, "AI engineer", 3.75);
    hoan.showInfo();
}