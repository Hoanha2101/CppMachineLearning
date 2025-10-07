#include <iostream>

using namespace std;

// ham template
template <typename T>
T add(T a, T b) {
    return a + b;
};

// class template
template <typename T>
class Vector2 {
    public:
        T x, y;
        Vector2(T x, T y) : x(x), y(y) {};

        T dot(Vector2<T> other) {
            return x * other.x + y * other.y;
        };
};

int main() {
    cout << "int: " << add(3, 4) << endl;
    cout << "float: "  << add(3.5f, 4.5f) << endl;

    Vector2<float> v1(1, 2);
    Vector2<int> v2(3, 4);

    cout << "dot: " << v1.dot(v1) << endl;
    cout << "dot: " << v2.dot(v2) << endl;

    Vector2<float> v3(1.5f, 2.5f);
    cout << "dot: " << v1.dot(v3) << endl;

    return 0;
}