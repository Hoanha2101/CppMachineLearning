#include <iostream>
#include <memory>
#include <vector>
using namespace std;
// Quản lý bộ nhớ nâng cao: unique_ptr, shared_ptr, weak_ptr, move semantics

class Resource {
    public:
    Resource() { cout << "Resource acquired\n"; }
    ~Resource() { cout << "Resource destroyed\n"; }
    void hello() {cout << "Hello, Resource!\n";}
};

/* 
✨ Đây là một phần của Rule of Five trong C++:
    Copy constructor
    Copy assignment
    Move constructor 
    Move assignment
    Destructor
*/

class Buffer {
public:
    int* data;
    size_t size;

    // 🟢 Constructor mặc định
    Buffer(size_t n = 0) : size(n) {
        if (size > 0)
            data = new int[size];
        else
            data = nullptr;
        cout << "Constructor: Buffer of size " << size << " allocated\n";
    }

    // 🟢 1. Copy constructor (deep copy)
    Buffer(const Buffer& other) : size(other.size) {
        if (size > 0) {
            data = new int[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        } else {
            data = nullptr;
        }
        cout << "Copy constructor called\n";
    }

    // 🟢 2. Copy assignment operator (deep copy)
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            // Xóa dữ liệu cũ
            delete[] data;

            // Sao chép dữ liệu mới
            size = other.size;
            if (size > 0) {
                data = new int[size];
                for (size_t i = 0; i < size; ++i)
                    data[i] = other.data[i];
            } else {
                data = nullptr;
            }
            cout << "Copy assignment operator called\n";
        }
        return *this;
    }

    // 🟢 3. Move constructor
    Buffer(Buffer&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called\n";
    }

    // 🟢 4. Move assignment operator
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            // Giải phóng tài nguyên cũ
            delete[] data;

            // Chuyển tài nguyên từ `other`
            data = other.data;
            size = other.size;

            // Vô hiệu hóa `other`
            other.data = nullptr;
            other.size = 0;

            cout << "Move assignment operator called\n";
        }
        return *this;
    }

    // 🟢 5. Destructor
    ~Buffer() {
        delete[] data;
        cout << "Destructor: Buffer of size " << size << " destroyed\n";
    }
};

int main() {
    // unique_ptr demo
    unique_ptr<Resource> up = make_unique<Resource>();
    up->hello();
    
    //transfer ownership
    unique_ptr<Resource> up2 = move(up);
    if (!up) cout << "up is null after move\n";

    // shared_ptr
    shared_ptr<Resource> s1 = make_shared<Resource>();
    cout << "use_count: " << s1.use_count() << "\n";

    {
        shared_ptr<Resource> s2 = s1;
        cout << "use_count after copy: " << s1.use_count() << "\n";
    }

    cout << "use_count after s2 goes out of scope: " << s1.use_count() << "\n";

    // weak_ptr
    weak_ptr<Resource> w = s1;
    cout << "weak expired: " << w.expired() << "\n";
    if (auto locked = w.lock()) {
        cout << "Locked weak_ptr, use_count: " << locked.use_count() << "\n";
        locked->hello();
    } else {
        cout << "Failed to lock weak_ptr\n";
    }

    // move semantics
    Buffer b1(5);
    Buffer b2 = move(b1); // move ctor called
}