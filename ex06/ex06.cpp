#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    // Constructor
    Complex(int real = 0, int imag = 0) : real(real), imag(imag) {}

    // Input Operator
    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }

    // Output Operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";  // "+" is for like 3 + 4i
        return out;
    }

    // Equality Operator
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Inequality Operator
    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    // Arithmetic Operators
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Increment Operators
    Complex& operator++() { // Prefix
        real++;
        imag++;
        return *this;
    }

    Complex operator++(int) { // Postfix
        Complex temp(*this);
        operator++(); // Prefix increment
        return temp;
    }

    // Decrement Operators
    Complex& operator--() { // Prefix
        real--;
        imag--;
        return *this;
    }

    Complex operator--(int) { // Postfix
        Complex temp(*this);
        operator--(); // Prefix decrement
        return temp;
    }

    // Compound Assignment Operator
    Complex& operator+=(const Complex& c) {
        real += c.real;
        imag += c.imag;
        return *this;
    }
};

int main() {
    Complex C1, C2;
    while (cin >> C1 >> C2) {
        cout << "C1 = " << C1 << endl;
        cout << "C2 = " << C2 << endl;

        cout << "C1==C2? " << ((C1 == C2) ? "true" : "false") << endl;

        cout << "C1+C2 = " << C1 + C2 << endl;
        cout << "C1-C2 = " << C1 - C2 << endl;
        cout << "C1*C2 = " << C1 * C2 << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "C1++  = " << C1++ << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "++C1  = " << ++C1 << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "C2--  = " << C2-- << endl;
        cout << "--C2  = " << --C2 << endl;
        cout << "--C2  = " << --C2 << endl;

        C1 += C2;
        cout << "C1+=C2  " << C1 << endl;
        cout << "==============" << endl;
    }
    return 0;
}
