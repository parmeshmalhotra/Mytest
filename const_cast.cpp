/*
This type of casting manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument:


*/

#include<iostream>
using namespace std;

void print (char *str)
{
cout<<str<<'\n';
}

int main()
{
const char *c = "sample text";
char d[20] = "sample 2";
print (d);
print (const_cast<char *>(c) );
return 0;
}

