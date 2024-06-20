#include <iostream>
using namespace std;

// Abstract Base Class Shape
class Shape {
    protected:
        int length;
    public:
        Shape() : length(0) {}
        Shape(int l) : length(l) {}
        virtual void act() = 0;
};

// Rectangle Class
class Rectangle : public Shape {
    public:
        Rectangle(int l) : Shape(l) {}
        void act() override {
            for (int i = 0; i < length; ++i) {
                for (int j = 0; j < length; ++j) {
                    cout << "@";
                }
                cout << endl;
            }
        }
};

// Triangle Class
class Triangle : public Shape {
    public:
        Triangle(int l) : Shape(l) {}
        void act() override {
            for (int i = 1; i <= length; ++i) {
                for (int j = 0; j < i; ++j) {
                    cout << "*";
                    if (j != i - 1) cout << " ";
                }
                cout << endl;
            }
        }
};

// Printer Class
class Printer {
    private:
        Shape* shape;
    public:
        Printer(Shape* s) : shape(s) {}
        void print() {
            shape->act();
        }
};

// Main function to demonstrate the functionality
int main() {
    int x, y;
    cin >> x >> y;

    Triangle tri(x);
    Rectangle rec(y);

    Printer printer1(&tri);
    Printer printer2(&rec);

    printer1.print();
    printer2.print();

    return 0;
}
