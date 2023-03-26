#include <iostream>
#include <cstdio>
using namespace std;

class Complex{
    
    private:
    	int m_i;
    	int m_j;
    public:
    	Complex(int i, int j): m_i(i), m_j(j){}
    	void output(){
            printf("(%d,%d)\n", m_i, m_j);
        }
    
    	Complex operator+(const Complex& x) const{
    		return Complex(m_i + x.m_i, m_j + x.m_j);
		}
};



int main() {

	Complex c1(11, 22);
    Complex c2(30, 40);
    Complex c3 = c1 + c2;
    c3.output();
    
	return 0;
}
