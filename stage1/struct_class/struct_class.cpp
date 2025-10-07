#include <iostream>
#include <string>

using namespace std;

struct Point {
    int x;
    int y;
};

class Student {
    private:
        string name;
        float score;
    
    public:
        Student( string n, float s ){
            name = n;
            score = s;
        }

        void showInfo() {
            cout << "Ten: " << name << ", Diem: " << score << endl;
        }

        float getScore() {
            return score;
        }

        void setScore (float newScore) {
            score = newScore;
        }
};

int main() {
    Point p1 = {3, 4};
    cout << "Toa do diem p1: " << p1.x << " , " << p1.y << endl;

    Student sv("Hoan", 10);
    sv.showInfo();
    cout << "Diem: " << sv.getScore() << endl;
    sv.setScore(9);
    cout << "Diem: " << sv.getScore() << endl;
    sv.showInfo();
};