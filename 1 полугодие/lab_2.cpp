#include <iostream>
#include <math.h> 
int main()
{
	unsigned char x = 7;
	// x = 00000111
	//unsigned char x = 98;
	// x = 01100010
	//unsigned char x = 241;
	// x = 11110001

	int i;
	std::cin >> i;

	unsigned int k = pow(2, i - 1); // 2 ** (i-1); 2^0=1, 2^1=10, 2^2=100, 2^3=1000
	bool res = k & x; // 0 or !0
	std::cout << res;


	return 0;
}