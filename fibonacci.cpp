#include <iostream>

template<int N>
struct fibonacci
{
	enum {value = fibonacci<N-1>::value+fibonacci<N-2>::value};
};

template<>
struct fibonacci<0>
{
	enum {value=0};
};

template<>
struct fibonacci<1>
{
	enum {value=1};
};


using namespace std;

int main()
{
	cout<<fibonacci<20>::value<<endl;
}
