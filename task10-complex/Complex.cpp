#include <iostream>
#include <cmath> 
using namespace std;

class Complex {
private:
    float* real;
    float* img;
public:
    Complex() {
        real = new float(0.0f);
        img = new float(0.0f);
    }
    Complex(float r, float i = 0.0f) {
        real = new float(r);
        img = new float(i);
    }
    Complex(const Complex& source) {
        real = new float(*(source.real));
        img = new float(*(source.img));
    }
    ~Complex() {
        delete real;
        delete img;
    }
    Complex& operator=(const Complex& source) {
        if (this == &source) return *this;
        *real = *(source.real);
        *img = *(source.img);
        return *this;
    }
    float getReal() const { return *real; }
    float getImg() const { return *img; }

    void setReal(float r) { *real = r; }
    void setImg(float i) { *img = i; }
    Complex operator+(const Complex& other) const {
        return Complex(*real + *(other.real), *img + *(other.img));
    }

    Complex operator-(const Complex& other) const {
        return Complex(*real - *(other.real), *img - *(other.img));
    }

    Complex operator*(const Complex& other) const {
        float r = (*real) * (*(other.real)) - (*img) * (*(other.img));
        float i = (*real) * (*(other.img)) + (*img) * (*(other.real));
        return Complex(r, i);
    }

    Complex operator/(const Complex& other) const {
        float denominator = (*(other.real)) * (*(other.real)) + (*(other.img)) * (*(other.img));
        float r = ((*real) * (*(other.real)) + (*img) * (*(other.img))) / denominator;
        float i = ((*img) * (*(other.real)) - (*real) * (*(other.img))) / denominator;
        return Complex(r, i);
    }

    Complex& operator+=(const Complex& other) {
        *real += *(other.real);
        *img += *(other.img);
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        *real -= *(other.real);
        *img -= *(other.img);
        return *this;
    }
    Complex& operator++() {
        (*real)++;
        (*img)++;
        return *this;
    }
    Complex operator++(int) {
        Complex temp = *this;
        (*real)++;
        (*img)++;
        return temp;
    }
    Complex& operator--() {
        (*real)--;
        (*img)--;
        return *this;
    }
    Complex operator--(int) {
        Complex temp = *this;
        (*real)--;
        (*img)--;
        return temp;
    }
    bool operator==(const Complex& other) const {
        return (*real == *(other.real) && *img == *(other.img));
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    bool operator>(const Complex& other) const {
        float mag1 = (*real) * (*real) + (*img) * (*img);
        float mag2 = (*(other.real)) * (*(other.real)) + (*(other.img)) * (*(other.img));
        return mag1 > mag2;
    }
    bool operator<(const Complex& other) const {
        float mag1 = (*real) * (*real) + (*img) * (*img);
        float mag2 = (*(other.real)) * (*(other.real)) + (*(other.img)) * (*(other.img));
        return mag1 < mag2;
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        if (*(c.real) == 0 && *(c.img) == 0) {
            os << "0";
            return os;
        }
        if (*(c.real) != 0) {
            os << *(c.real);
        }
        if (*(c.img) < 0) {
            if (*(c.real) != 0) os << " - " << -(*(c.img)) << "i";
            else os << "-" << -(*(c.img)) << "i";
        }
        else if (*(c.img) > 0) {
            if (*(c.real) != 0) os << " + " << *(c.img) << "i";
            else os << *(c.img) << "i";
        }
        return os;
    }
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter Real Part: ";
        is >> *(c.real);
        cout << "Enter Imaginary Part: ";
        is >> *(c.img);
        return is;
   }
    explicit operator double() const {
        return static_cast<double>(*real);
    }
    void operator()() const {
        cout << *this << endl;
    }
};
int main() {
    cout << " Constructors & Streams " << endl;
    Complex c1(5, 5);
    Complex c2(2, -3);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "Math & Assignments " << endl;
    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;

    c1 += c2;
    cout << "c1 after += c2: " << c1 << endl;

    cout << " Increments " << endl;
    Complex post = c2++;
    cout << "c2++ (Returned value): " << post << endl;
    cout << "c2 now (Incremented): " << c2 << endl;

    cout << " Comparisons " << endl;
    if (c1 > c2) cout << "c1 has a larger magnitude than c2" << endl;

    cout << " TypeCasting (to double) " << endl;
    double realPart = static_cast<double>(c2);
    cout << "Real scalar extracted via casting: " << realPart << endl;

    cout << " Function Call Operator obj() " << endl;
    cout << "Executing c1(): ";
    c1();

    return 0;
}
