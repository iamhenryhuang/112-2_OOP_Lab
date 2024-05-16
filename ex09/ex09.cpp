#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int real = 0, int imag = 0) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // z1 = a + bi, z2 = c + d1
    //newReal = ac - bd, newImag = ab + bc
    Complex operator*(const Complex& other) const {
        int newReal = real * other.real - imag * other.imag;
        int newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    friend ostream& operator<<(ostream& os, const Complex& comp) {
        if (comp.imag >= 0) {
            os << comp.real << "+" << comp.imag << "i";
        } else {
            os << comp.real << comp.imag << "i";
        }
        return os;
    }
};

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

int main() {
    string type;
    while (cin >> type) {
        if (type == "int") {
            int a, b;
            cin >> a >> b;
            cout << add(a, b) << endl;
            cout << subtract(a, b) << endl;
            cout << multiply(a, b) << endl;
        } else if (type == "float") {
            float a, b;
            cin >> a >> b;
            cout << fixed << setprecision(2) << add(a, b) << endl;
            cout << fixed << setprecision(2) << subtract(a, b) << endl;
            cout << fixed << setprecision(2) << multiply(a, b) << endl;
        } else if (type == "Complex") {
            int real1, imag1, real2, imag2;
            cin >> real1 >> imag1 >> real2 >> imag2;
            Complex comp1(real1, imag1), comp2(real2, imag2);
            cout << add(comp1, comp2) << endl;
            cout << subtract(comp1, comp2) << endl;
            cout << multiply(comp1, comp2) << endl;
        }
    }
    
    return 0;
}
