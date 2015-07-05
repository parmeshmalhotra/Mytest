#include<iostream>
#include "Foo.H"
int main()
{
	int i =1;
	int j[] = {2,3};
	{
		Foo a(i),b(j[0]),c(j[1]);
		i= j[0];
		j[0] = j[1];
		j[1] = i;
		std::cout<<i<<j[0]<<j[1]<<std::endl;
	}
        std::cout<<i<<j[0]<<j[1]<<std::endl;
	return 0;
}

