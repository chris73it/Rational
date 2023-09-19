#include <iostream>
#include "Rational.h"

int main()
{
	Rational r5{ 5, 7 };
	std::cout << r5 << std::endl;
	Rational r6{ 2, 3 };
	std::cout << r6 << std::endl;
	
	Rational r7a = r5 + r6;
	std::cout << "[+] " << r7a << std::endl;

	r7a = r5 - r6;
	std::cout << "[-] " << r7a << std::endl;

	r7a = r5 * r6;
	std::cout << "[*] " << r7a << std::endl;

	r7a = r5 / r6;
	std::cout << "[/] " << r7a << std::endl;

	return 0;
}
