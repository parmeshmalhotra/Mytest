#include<iostream>

using namespace std;

class A {
	int m_a;
	public:
	A():m_a(0){}
        A(int a):m_a(a){
		cout<<"Calling constructor \n";

	}
	~A(){
		cout<<"Calling destructor \n";

	}
	A( const A& obj)
	{
		cout<<"Calling copy constructor\n";
		m_a = obj.m_a;
	}
	A& operator =(const A &obj)
	{
		cout<<"Calling assignment operator \n";
		m_a =obj.m_a;
	}
};


int main()
{
 A o1(5);
 A o2 = o1;
 A o3;
 o3=o1;
 return 0;
}
 
