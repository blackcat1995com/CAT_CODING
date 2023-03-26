#include <iostream>
#include <cstdio>
using namespace std;

class Complex{
    friend Complex operator+(const Complex&, const Complex&);
    private:
    	int m_i;
    	int m_j;
    
    public:
    	Complex(int i, int j): m_i(i), m_j(j){}
    	void output(){
            printf("(%d,%d)\n", m_i, m_j);
        }
};

Complex operator+(const Complex& c1, const Complex& c2){
    return Complex(c1.m_i + c2.m_i, c1.m_j + c2.m_j);
}

int main() {

	Complex c1(10, 20);
    Complex c2(30, 40);
    Complex c3 = c1 + c2;
    c3.output();
    
	return 0;
}
