#include <iostream>
#include <memory>
using namespace std;

class Student {
    public:
        string name;
        Student(string n) : name(n) {
            cout << "Tao sinh vien: " << name << endl;
        };
        ~Student() {
            cout << "Huy sinh vien: " << name << endl;
        };
};

int main() {
    {
        unique_ptr<Student> sv = make_unique<Student>("Hoan1");
    } // Tự động hủy sv ở đây, không cần delete

    unique_ptr<Student> sv = make_unique<Student>("Hoan2");

    shared_ptr<Student> sv1 = make_shared<Student>("Kinh");
    shared_ptr<Student> sv2 = sv1; // share cùng đối tượng
    sv2->name = "Nguyen";
    cout << "Ten: " << sv1->name << " , " << sv2->name << endl;
    
    cout << "So luong: " << sv1.use_count() << endl;
    cout << "So luong: " << sv2.use_count() << endl;
    cout << "--------------------------------" << endl;
    sv1.reset();
    cout << "So luong: " << sv1.use_count() << endl;
    cout << "So luong: " << sv2.use_count() << endl;


}