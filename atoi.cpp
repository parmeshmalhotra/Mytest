#include<iostream>
using namespace std;
int atoi_fun( char *str)
{
int i=0;
int d;
int res=0;
while(str[i]!='\0')
{
 d= str[i]-'0';
 res=res*10+d;
 i++;
}

return res;
}



int main()
{
int i;
char a[10];
for (i=0;i<9;i++)
{
a[i] ='1';
}
a[i] = '\0';
char s[] = "1234";
cout<<atoi_fun(a);
}


