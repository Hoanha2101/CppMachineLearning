#include <iostream>
using namespace std;

template <typename T>
T MyMax(T a, T b) {
    return (a >= b) ? a : b;
}

template <typename T>
class vector2D {
    public:
        T x, y;
        vector2D(T x, T y): x(x), y(y) {}
        vector2D operator+(const vector2D& other) const {
            return vector2D(x + other.x, y + other.y);
        }

        T dot(const vector2D& other) const {
            return x*other.x + y*other.y;
        }

        void print() const {
            cout << "(" << x << ", " << y << ")" << endl;
        }
};


int main() {
    cout << "MyMax(3, 5) = " << MyMax(3, 5) << endl;
    cout << "MyMax(3.5, 2.5) = " << MyMax(3.5, 2.5) << endl;
    cout << "MyMax('A', 'B') = " << MyMax('A', 'B') << endl;

    vector2D<int> v1(1,2), v2(3,4);
    vector2D<int> v3 = v1 + v2;
    cout << "v1 + v2 = "; v3.print();
    cout << "dot: " << v1.dot(v2) << endl;  
}

    
