/*
However, when designing classes that handle dynamically allocated memory, memberwise (shallow) copying can get us in a lot of trouble! This is because the standard pointer assignment operator just copies the address of the pointer -- it does not allocate any memory or copy the contents being pointed to!
/*
*/

#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class MyString
{
	private:
		char *m_pchString;
		int m_nlength;
	public:
		MyString(char *pchString = "")
		{
			m_nlength = strlen(pchString) +1;
			m_pchString = new char[m_nlength];
			strncpy(m_pchString,pchString,m_nlength);
			m_pchString[m_nlength-1] = '\0';
		}
		~MyString()
		{
			delete[] m_pchString;
			m_pchString=0;
		}

		// Copy constructor
		MyString(const MyString& cSource)
		{
			// because m_nLength is not a pointer, we can shallow copy it
			m_nlength = cSource.m_nlength;

			// m_pchString is a pointer, so we need to deep copy it if it is non-null
			if (cSource.m_pchString)
			{
				// allocate memory for our copy
				m_pchString = new char[m_nlength];

				// Copy the string into our newly allocated memory
				strncpy(m_pchString, cSource.m_pchString, m_nlength);
			}
			else
				m_pchString = 0;
		}

		char * GetString()
		{
			return m_pchString;
		}

		int GetLength() { return m_nlength;}
};

int main()
{
	MyString cHello("Hello,World!");
	{
		MyString cCopy = cHello;
	}
	cout<<cHello.GetString()<<endl;

	return 0;
}
