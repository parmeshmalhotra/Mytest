#include<iostream>
#include<exception>
/*
dynamic_cast can only be used with pointers and references to classes (or with void*). Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.
*/

using namespace std;

class Base
{
virtual void dummy(){}
};

class Derived: public Base
{
int a;
};
int main()
{

 try {
	Base* pba=new Derived;
	Base* pbb=new Base;
	Derived *pd;
	
	pd = dynamic_cast<Derived*>(pba);
	if (pd == 0) cout<<"Null pointer on first type-cast \n";

	pd = dynamic_cast<Derived*>(pbb);
	if (pd == 0) cout<<"Null pointer on second type-cast \n";
      }
 catch (exception& e)
 {
	 cout<<"Exception: "<<e.what();
 }
 return 0;
}


