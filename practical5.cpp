#include <iostream>
using namespace std;
class Complex {
private:
    float real;
    float imag;
public:
    // a. Default constructor: creates 0+0i
    Complex() {
        real = 0;
        imag = 0;
    }
    // Parameterized constructor
    Complex(float r, float i) {
        real = r;
        imag = i;
    }
    // b. Overload operator+ to add two complex numbers
    Complex operator+(const Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    // c. Overload operator* to multiply two complex numbers
    // (a+bi)(c+di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex &c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }
    // d. Overload >> to read a complex number
    friend istream& operator>>(istream &in, Complex &c) {
        cout << "\nEnter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
    // d. Overload << to print a complex number
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};
int main()
{
    Complex c1;          // Default constructor: 0 + 0i
    Complex c2(4, 2);    // Parameterized constructor: 4 + 2i
    Complex c3, sum, prod;
    cout << "Default constructed number: " << c1 << endl;
    cout << "\nFirst complex number: " << c2 << endl;
    cout << "\nEnter second complex number:";
    cin >> c3;
    cout << "\nSecond complex number: " << c3 << endl;
    sum = c2 + c3;
    prod = c2 * c3;
    cout << "\nSum: " << sum << endl;
    cout << "Product: " << prod << endl;
    return 0;
}
