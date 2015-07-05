#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<typename T>
void print(const vector<T>& v, const char* delim) {
	copy(v.begin(), v.end(), ostream_iterator<T>(cout, delim));
	cout << endl;
}

template<typename T>
const vector<T>& shifted_vector(vector<T>& v, const T& value) {
	typename vector<T>::iterator start(v.begin()), end(v.end());
  typename vector<T>::iterator found = find(start,end,value);
	while(found != end) {
		typename vector<T>::iterator it(found), prev = it-1;
		while(it != start && *it != *prev){
			swap(*it, *prev); 
			--it; --prev;
		}
		found = find(found,end,value);
	}
	return v;
}

int main() {
	int arr[] = {1,3,0,9,6,7,0,8,4,0,2,0,5,0,0,0,4,0};
	int size = sizeof(arr)/sizeof(int);
	vector<int> vect(arr,arr+size);
	print<int>(vect," ");
	print<int>(shifted_vector<int>(vect,4)," ");
	return 0;
}
