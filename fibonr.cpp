#include<iostream>
using namespace std;

void fibo(int n)
{
	int a=0;
	int b=1;
	int c,i;
        if (n>0)
         {
           cout<<a<<endl;
         }
        if (n>1)
         {
         cout<<b<<endl;
         }
        if (n>2)
        {
	for (i=0;i<n-2;i++)
	{
		c=a+b;
		a=b;
                b=c;
	//	cout <<c<<endl;
	}
        cout<<b;
        }
}

int main()
{
fibo(5);
}
