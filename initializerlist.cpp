#include<iostream>
using namespace std;


class A
{
	int &m_c;
	const int m_a;
	int m_b;
        static int d;
	public:
	A(int& c , const int a,int b):m_c(c),m_a(a),m_b(b) 
	{
		cout<<"A: "<<a<<endl;
		cout<<"B: "<<b<<endl;
		cout<<"C: "<<c<<endl;
		cout<<"D: "<<d<<endl;
	}
};
int A::d=40;

int main()
{
 int a=10;
 int b=20;
 int c=30;
 A obj(c,a,b);
} 
