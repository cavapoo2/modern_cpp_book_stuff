#pragma once
#include<numeric>
unsigned int gcd(unsigned int const a, unsigned int const b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(unsigned  int const a, unsigned int const b)
{
	int h = gcd(a, b);
	return h ? (a * (b / h)) : 0;
}

template<class InputIt>
int lcmr(InputIt first, InputIt last)
{
	return std::accumulate(first, last, 1, lcm);
}

