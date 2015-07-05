#include<iostream>
class Foo 
{
	int &m_val;//reference copy
	int m_copy;//value copy
	public:
	Foo(int &value):m_val(value),m_copy(value)
        {}; 
	~Foo()
	{
	 m_val =m_copy *10;
	}
};
	
