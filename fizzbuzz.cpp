#include <iostream>

using std::cout;
using std::endl;

template<int N, int m3=N%3, int m5=N%5>
struct FzBzDecider
{
	static void Prnt(void)
		{
			cout << N << endl;
		}
};

template<int N, int m3>
struct FzBzDecider<N,m3,0>
{
	static void Prnt(void)
		{
			cout << "Fizz" << endl;
		}
};

template<int N, int m5>
struct FzBzDecider<N,0,m5>
{
	static void Prnt(void)
		{
			cout << "Buzz" << endl;
		}
};
template<int N>
struct FzBzDecider<N,0,0>
{
	static void Prnt(void)
		{
			cout << "FizzBuzz" << endl;
		}
};



	
template<int value, int final>
struct tloop
{
	static void Op(void)
		{
			// int i = &std::string("hello")[0]; way to make warnings?
			FzBzDecider<value>::Prnt();
			tloop<value+1,final>::Op();
		};
};

template<int value>
struct tloop<value,value>
{
	static void Op(void)
		{
			FzBzDecider<value>::Prnt();
		};
};

int main()
{
	tloop<1,10>::Op();


}
