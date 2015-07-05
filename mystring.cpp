// Author:  Melissa Danforth
// Purpose: HW3 mystring source file. This has the bodies of all the functions

#ifndef __MYSTRING_CPP__
#define __MYSTRING_CPP__

#include <iostream>
#include <cstring>
#include "mystring.h"
using namespace std;

// Constructors and destructor

// Set the array to NULL
myString::myString()
{
  str = NULL;
  size = 0;
}

// Copy a over to 'this' object
myString::myString(const myString &a)
{
  size = a.size;
  str = new char[size];
  // Use strcpy to copy the string and eliminate the need for a for() loop
  strcpy(str, a.str);
}

// Copy s over to 'this' object
myString::myString(const char *s)
{
  // size is the length of s plus 1 for the null character
  size = strlen(s) + 1;
  str = new char[size];
  strcpy(str, s);
}

// Create a one character long string
myString::myString(const char c)
{
  // size is 1 char plus null character
  size = 2;
  str = new char[size];
  str[0] = c;
  str[1] = '\0';
}

// Delete the allocated string. No need to change size as the object is
// being destroyed, so size will never be accessed again for this object
myString::~myString()
{
  delete [] str;
}

// Member functions

// Wrap around strlen. Have to check that the array is allocated first.
int myString::length() const
{
  if(size > 0) return strlen(str);
  return 0;
}

// string can be erased by setting the first character to the null character
void myString::erase()
{
  str[0] = '\0';
}

// Create a second string that is the reverse of str
char *myString::reverse() const
{
  int i; // index for str
  int j = 0; // index for s
  char *s;

  s = new char[size];
  // Start str's index at length() - 1 to skip over the null character
  // If started at length(), the first character copied over to s would
  // be the null character, which would make s the empty string
  for(i = length() - 1; i >= 0; i--)
  {
    // Copy the i-th character of str to the j-th character of s
    // Since we're looping backwards through str, this will copy str
    // backwards into s
    s[j] = str[i];
    j++;
  }
  return s;
}

// Create a wrapper around i.getline(). Must allocate enough space in str
// if the current size is not large enough to hold count characters
void myString::getline(istream &i, int count)
{
  // Clear \n off the input buffer before calling getline()
  i.ignore(100, '\n');

  // Only need to compare against count as i.getline() will delete 1 from
  // count for the null character
  if(size < count)
  {
    delete [] str;
    size = count;
    str = new char[size];
  }
  i.getline(str, count);
}

// Operators that are member functions

// Assignment is similar to the copy constructor, but we have to delete
// the string if it already exists
void myString::operator =(const myString &right)
{
  if(size > 0) delete [] str;
  size = right.size;
  str = new char[size];
  strcpy(str, right.str);
}

// Append takes the string in right and adds it to the current string.
// If we do not have enough space for the combined string, we need to
// reallocate str.
void myString::operator +=(const myString &right)
{
  // Create a backup of the current string using the 'this' pointer
  myString tmp = *this;
  int final_size;

  // The total size to store the new string is our length plus right's 
  // length plus 1 for the null character
  final_size = length() + right.length() + 1;
  if(size < final_size)
  {
    delete [] str;
    size = final_size;
    str = new char[size];
    // Restore the original value of str from the backup in tmp
    strcpy(str, tmp.str);
  }

  // Concatenate right's string onto the current string
  strcat(str, right.str);
}

// This is the unbounded index operator. Like the index operator in the C++
// predefined array types (int arrays and so forth), it does not check that
// the index is a valid index.
// However, we do have to check that str is allocated, otherwise there will
// be no array to index into.
char myString::operator [](int index) const
{
  if(size > 0) return str[index];
  // No array allocated, return the null character
  return '\0';
}

// Operators that are friends

// The input operator assumes a maximum word size and reallocates str if
// it is not that large. The maximum word size is the constant MAX_WORD
// defined in the header file.
istream &operator >>(istream &left, myString &right)
{
  if(right.size < MAX_WORD)
  {
    delete [] right.str;
    right.size = MAX_WORD;
    right.str = new char[right.size];
  }
  left >> right.str;

  return left;
}

// Output the string if it has been allocated
ostream &operator <<(ostream &left, const myString &right)
{
  if(right.size > 0)
  {
    left << right.str;
  }

  return left;
}

// Concatenate left and right into a new string variable
myString operator +(const myString &left, const myString &right)
{
  myString temp;

  // temp's size has to be big enough to hold both strings. 
  temp.size = left.size + right.size;
  temp.str = new char[temp.size];

  // Copy left in first
  strcpy(temp.str, left.str);
  // Now concat right
  strcat(temp.str, right.str);

  // return the new string
  return temp;
}

// For all of the boolean operators, wrap around strcmp(left, right)
//   strcmp(left, right) returns...
//      0            if left == right
//      negative     if left < right
//      positive     if left > right
bool operator <(const myString &left, const myString &right)
{
  int i = strcmp(left.str, right.str);
  // will return true if i is negative, false otherwise
  return (i < 0);
}

bool operator >(const myString &left, const myString &right)
{
  int i = strcmp(left.str, right.str);
  // will return true if i is positive, false otherwise
  return (i > 0);
}

bool operator ==(const myString &left, const myString &right)
{
  int i = strcmp(left.str, right.str);
  // will return true if i is 0, false otherwise
  return (i == 0);
}

bool operator !=(const myString &left, const myString &right)
{
  int i = strcmp(left.str, right.str);
  // will return true if i is not 0, false otherwise
  // NOTE: this could also be return i since most compilers convert 0 to false
  //       and non-zero to true.
  return (i != 0);
}

#endif
