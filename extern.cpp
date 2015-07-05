#include<iostream>
#include "extern.h"

int global1=30;
int global2=40;

object::object(void)
{
 m=0;
}

int object::set(int newval)
{
int local1=10;
global1=60;
global2=70;
return newval;
}

object::~object(void)
{
m=0;
}


