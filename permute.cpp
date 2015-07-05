#include<iostream>

using namespace std;

void swap (char &a,char &b)
{
 char c=a;
 a=b;
 b=c;
}


int permute(char set[], int begin, int end)                                                                          //declare premute function
{
	int i;                                                                                                      //declare variable i
	int range = end - begin;                                                                                    //declare variable range
	if (range == 0)                                                                                             //selection
	{
		cout<<"display:"<<set<<endl;                                                                          //output                                                                   
	}
	else {                                                                                                  //selection
		for(i=0; i<range; i++)                                                                          //loop
		{ 
			swap(set[begin], set[begin+i]);                                                           //function
			permute(set, begin+1, end);                                                                 //recursive function
			swap(set[begin], set[begin+i]);                                                           //function
			/*reset*/
		}
	}
	return 0;                                                                                                   //return 0
}

int main()
{
 char a[] = "abc";
 permute(a,0,3);
 cout<<"Original"<<a;
}
