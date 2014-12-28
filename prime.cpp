#include <iostream>
#include <iomanip>

#include <cmath>
#include <cassert>


template<int N>
struct tsqrt
{
  static constexpr int rt = std::sqrt(N);
};

template<int P, int N>
struct is_prime
{
  constexpr static bool value = (P%N==0) ?  0 : is_prime<P, N+1>().value  ;
  /*
  // this version isn't stopping...
  constexpr static bool value = (P%N==0) ? 
    0 : ( ( N==tsqrt<P>().rt ) ? 1 : is_prime<P, N+1>().value ) ;
  // can use '==' or '>' doesn't work on either
  */
};

template<int P>
struct is_prime<P,P>
{
  constexpr static bool value = true;
};





using namespace std;


int main()
{
  cout<<boolalpha;
  cout<<is_prime<1061,2>::value<<endl;

  // static_assert(tsqrt<1061>().rt==32,"");
  //  static_assert(is_prime<1060,2>::value==0,"");

}
