#include <iostream>

template<int N>
struct factorial
{
	enum {value = N*factorial<N-1>::value};
};

template<>
struct factorial<0>
{
	enum {value=1};
};

using namespace std;

int main()
{
	cout<<factorial<12>::value<<endl;
}
