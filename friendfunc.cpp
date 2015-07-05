#include <iostream>
using namespace std;

class B; // forward declaration

class A {
	private:
	 int data;
	public:
	 A(): data(12) {}
	 friend int func(A,B);
};

class B {
	private:
	 int data;
	public:
	 B():data(1) {}
	 friend int func(A,B);
};


int func ( A d1, B d2)
{
return (d1.data+d2.data);
}

int main()
{

A a;
B b;
cout<<"Data: "<<func(a,b);
}
