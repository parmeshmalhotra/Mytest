#include<iostream>
#include<stdlib.h>
#include"extern.h"
using namespace std;
int main()
{
object f1;
extern int global2;
int local2=20;
cout<<"In extern.h, global1 is object.cpp external variable = "<<global1<<endl;
cout<<"In mainextern.cpp, global2 is object.cpp external variable ="<<global2<<endl;
cout<<"In mainextern.cpp, object value =  "<<f1.set(50)<<"\n";
cout<<"In mainextern.cpp, local function, local2 variable = "<<local2<<endl;
cout<<"In extern.h, global1 is object.cpp external variable = "<<global1<<endl;
cout<<"In mainextern.cpp, global2 is object.cpp external variable ="<<global2<<endl;
}
