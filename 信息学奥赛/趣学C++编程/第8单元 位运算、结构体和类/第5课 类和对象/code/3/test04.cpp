#include <iostream>
#include <cstdio>
using namespace std;

class Complex{
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, const Complex&);
    private:
    	int m_i;
    	int m_j;
    public:
    	Complex(){}
    	Complex(int i, int j): m_i(i), m_j(j){}
    	void output(){
            printf("(%d,%d)\n", m_i, m_j);
        }
    	
    	// 单目运算符重载
    	Complex operator-() const{
    		return Complex(-m_i, -m_j);
		}
    
    	// 前置++ : ++对象
    	Complex& operator++(){
            ++m_i;
            ++m_j;
            return *this;
        }
    
    	// 后置++：对象++
    	Complex operator++(int){
            Complex pre(m_i, m_j);
            m_i++;
            m_j++;
            return pre;
        }
};

ostream& operator<<(ostream& cout, const Complex& x){
    printf("(%d,%d)", x.m_i, x.m_j);
    return cout;
}
istream& operator>>(istream& cin, const Complex& x){
    scanf("%d%d", &x.m_i, &x.m_j);
    return cin;
}

int main() {

	Complex c1(11, 22);
    Complex c2(30, 40);
    Complex c3 = c2++;
    // cout << c1 << " " << c2 << endl;
    
    Complex c4;
    cin >> c4;
    cout << c4 << endl;
    // c3.output();
    // c2.output();
	return 0;
}
