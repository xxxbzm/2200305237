#include <iostream>
#include <cmath>
using namespace std;
//复数类
class Complex {
public:  //构造函数
    Complex(double real = 0, double imag = 0) : m_real(real), m_imag(imag) { }
public:  //运算符重载
    //以全局函数的形式重载
    friend bool operator> (const Complex& c1, const Complex& c2);
    friend bool operator< (const Complex& c1, const Complex& c2);
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);
    void display();
    double read_Real(double r);
    double read_Imaginary(double i);
    double read_modulus();
    double display2();
public:  //成员函数
    double real() const { return m_real; }
    double imag() const { return m_imag; }
    double modulus() const { return m_modulus; }
    double m_real;  //实部
    double m_imag;  //虚部
    double m_modulus;  //模长 
};
//重载==运算符
bool operator==(const Complex& c1, const Complex& c2) {
    if (c1.m_real == c2.m_real && c1.m_imag == c2.m_imag) {
        return true;
    }
    else {
        return false;
    }
}
//重载> <运算符 
bool operator>(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus > c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>(const Complex& c1, double m) {
    if (c1.m_modulus > m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus < c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<(const Complex& c1, double m) {
    if (c1.m_modulus < m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(const Complex& c1, const Complex& c2) {
    if (c1.m_modulus <= c2.m_modulus) {
        return true;
    }
    else {
        return false;
    }
}
bool operator<=(const Complex& c1, double m) {
    if (c1.m_modulus <= m * m) {
        return true;
    }
    else {
        return false;
    }
}
bool operator>=(const Complex& c1, double m) {
    if (c1.m_modulus >= m * m) {
        return true;
    }
    else {
        return false;
    }
}
//重载!=运算符
bool operator!=(const Complex& c1, const Complex& c2) {
    if (c1.m_real != c2.m_real || c1.m_imag != c2.m_imag) {
        return true;
    }
    else {
        return false;
    }
}
//显示复数 
void Complex::display() {
    if (m_real != 0) {
        if (m_imag > 0) {
            cout << m_real << "+" << m_imag << "i" << " ";
        }
        else cout << m_real << m_imag << "i" << " ";
    }
    if (m_imag == 0)
        cout << m_imag << "i" << " ";
}
double Complex::display2() {
    double x = m_modulus;
    return x;
}
//实部 虚部 模 
double Complex::read_Real(double r) {
    m_real = r;
}
double Complex::read_Imaginary(double i) {
    m_imag = i;
}
double Complex::read_modulus() {
    m_modulus = m_imag * m_imag + m_real * m_real;
}
